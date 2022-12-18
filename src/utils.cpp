#include <iostream>

#include "../include/utils.hpp"

void utils::fancy_box_print(const std::string& str)
{
    int left = (61 - str.length()) / 2;
    int right = (60 - str.length()) / 2;
    std::cout << "+"
              << std::string(60, '-')
              << "+" << std::endl
              << "|" + std::string(60, ' ') + "|"
              << std::endl
              << "|"
              << std::string(left, ' ') + str + std::string(right, ' ')
              << "|"
              << std::endl
              << "|" + std::string(60, ' ') + "|"
              << std::endl
              << "+"
              << std::string(60, '-')
              << "+" << std::endl
              << std::endl;
}
