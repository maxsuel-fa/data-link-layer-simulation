#include <iostream>

#include "../include/transmission_medium.hpp"
#include "../include/data_link_layer.hpp"
#include "../include/utils.hpp"
#include "../include/constants.hpp"

void TransmissionMedium::send(std::vector<bool>& frame)
{
    utils::fancy_box_print("Transmission Medium");
    std::cout << "Sending the Message to the Receiver Node..."
              << std::endl;
    disturb(frame, consts::error_likelihood);
    DLL::receive(frame);
}

void TransmissionMedium::disturb(std::vector<bool>& frame, 
                                const int& error_likelihood)
{
    srand(time(NULL));
    if (rand() % 100 < error_likelihood)
    {
        int index = (rand() % (frame.size() - 1));
        frame[index] = !frame[index];
    }
}
