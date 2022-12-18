#include <iostream>
#include <string>

#include "../include/simulation.hpp"
#include "../include/application_layer.hpp"
#include "../include/utils.hpp"

void Simulation::run(void)
{
    utils::fancy_box_print("Welcome to the Network Simulator");
    std::cout << std::endl
              << std::endl;

    std::cout << "Enter the message you want to send: ";
    std::string message;
    std::getline(std::cin, message);

    std::cout << std::endl
              << "Sent Message: "
              << message
              << std::endl;
    
    ApplicationLayer::send(message);
}
