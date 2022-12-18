#include "../../include/data_link_layer.hpp"
#include "../../include/constants.hpp"

DLL::DLL(const std::string& id) : id_ { id } {}

void DLL::send(std::vector<bool>& frame)
{
    add_checker(frame);
    transport_layer.send(frame);
}

void DLL::add_checker(std::vector<bool>& frame)
{
    switch (consts::checker_type)
    {
    case consts::even_parity:
        add_even_parity_checkbit(frame);
        break;
    case consts::odd_parity:
        add_parity_checkbit(frame, false);
        break;
    case consts::crc_check:
        add_crc32_check(frame);
        break;
    }
}

void DLL::add_parity_checkbit(std::vector<bool>& frame,
                              const bool& even_parity = true)
{
    auto count(std::count(frame.begin(), frame.end(), true));
    frame.push_back((count % 2 == 0) ^ even_parity);
}

void DLL::add_crc32_check(std::vector<bool>& frame)
{
    // crc32_pol represents the polinomio:
    // x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10
    // + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1
    std::vector<bool> crc32_pol
    {
        1, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 1, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 1, 1, 1, 0,
        1, 1, 0, 1, 1, 0, 1, 1, 1
    };

    std::vector<bool> remainder{frame};
    remainder.resize(remainder.size() + 32);
    for (size_t i = 0; i < remainder.size() - 32; ++i)
    {
        if (remainder[i])
        {
            // Element-wise XOR between the remainder and the crc32_pol
            // to get the modulo two division
            for (size_t j = 0; j < crc32_pol.size(); ++j)
            {
                remainder[i + j] ^= crc32_pol[j];
            }
        }
        remainder[i] = frame[i];
    }
    // Stores the remainder of the division and the frame together in order to
    // check errors
    frame.clear();
    frame = remainder;
}

bool DLL::check_parity_bit(const std::vector<bool>& frame,
                           const bool& even_parity = true)
{
    auto count(std::count(frame.begin(), frame.end(), true));
    return !((count % 2 == 0) ^ even_parity)
}

bool DLL::crc32_check(std::vector<bool>& frame)
{
    // crc32_pol represents the polinomio:
    // x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10
    // + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1
    std::vector<bool> crc32_pol
    {
        1, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 1, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 1, 1, 1, 0,
        1, 1, 0, 1, 1, 0, 1, 1, 1
    };

    std::vector<bool> remainder{frame};
    for (size_t i = 0; i < remainder.size() - 32; ++i)
    {
        if (remainder[i])
        {
            // Element-wise XOR between the remainder and the crc32_pol
            // to get the modulo two division
            for (size_t j = 0; j < crc32_pol.size(); ++j)
            {
                remainder[i + j] ^= crc32_pol[j];
            }
        }
        remainder[i] = frame[i];
    }

    bool has_error(false);
    for(auto bit : remainder)
        if(bit)
            has_error = bit;
    frame.clear();
    frame.insert(frame.begin(), remainder.begin(), remainder.end() - 32);
    frame.resize(remainder.size() - 32);

    return has_error;
}
