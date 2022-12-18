#include <iostream>
#include <algorithm>
#include <bitset>

#include "../../include/application_layer.hpp"
#include "../../include/utils.hpp"

void ApplicationLayer::send(const std::string& message)
{
    std::vector<bool> frame;

    for (const char& c : message)
    {
        std::bitset<8> byte(c);
        for (size_t i = 0; i < byte.size(); ++i)
            frame.push_back(byte[i]);
    }

    utils::fancy_box_print("Transmitter Application Layer");
    std::cout << "String to Bits Transformation..."
              << std::endl;

    DLL::send(frame);
}

void ApplicationLayer::receive(std::vector<bool>& frame)
{
    size_t message_length((frame.size() + 8 - 1) / 8);
    std::string message(message_length, 0);
    auto message_iter = message.begin();

    // Convert the frame into a string
    int shift(0);
    for (auto bit : frame)
    {
        (*message_iter) |= (bit << shift);
        ++shift;

        if (shift == 8)
        {
            ++message_iter;
            shift = 0;
        }
    }

    utils::fancy_box_print("Receiver Application Layer");
    std::cout << "Bits to String Transformation..."
              << std::endl;
    std::cout << "Received Message: "
              << message
              << std::endl;
}
