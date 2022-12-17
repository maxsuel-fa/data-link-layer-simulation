#include <algorithm>

#include "../../include/application_layer.hpp"

ApplicationLayer::ApplicationLayer(const std::string& id) : id_ { id } {}

void ApplicationLayer::send(const std::string& message, const DLL& dll)
{
    std::vector<bool> frame;

    for (char& c : message)
    {
        std::bitset<8> byte(c);
        for (bool bit : byte)
            frame.push_back(bit);
    }

    dll.receive(frame);
}

std::string ApplicationLayer::receive(const std::vector<bool> frame)
{
    size_t message_length((frame.size() + 8 - 1) / 8);
    std::string(message_length, 0);
    auto message_iter = message.begin();

    // Reverse the frame from 8 to 8 bits
    std::reverse(frame.begin(), frame.begin() + 8);
    std::reverse(frame.begin() + 8, frame.end());

    // Convert the frame into a string
    int shift(0);
    for(auto bit : frame)
    {
        (*message_iter) |= (bit << shift);
        ++shift;

        if(shift == 8)
        {
            ++message_iter;
            shift = 0;
        }
    }

    return message;
}

void ApplicationLayer::id(const std::string& id)
{
    id_ = id;
}

const std::string& id(void)
{
    return id_;
}
