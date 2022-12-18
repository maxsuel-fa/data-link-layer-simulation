#pragma once
// STD includes
#include <string>
#include <vector>


// Local library includes
#include "./application_layer.hpp"

/**
 * @brief The data link layer of the network
 */
class DLL
{
public:
    DLL(void) = default;


    /**
     * @brief Given a frame, transmits it to the transport layer
     * @param frame The frame to be transmited
     */
    static void send(std::vector<bool>& frame);

    /**
     * @brief Interface between the data link and the transport layers
     * @param frame The message received from the transport layer as a bit set
     */
    static void receive(std::vector<bool>& frame);


    static void add_checker(std::vector<bool>& frame);
    static void add_parity_checkbit(std::vector<bool>& frame,
                             const bool& even_parity);
    static void add_crc32_check(std::vector<bool>& frame);
    static bool check_parity_bit(std::vector<bool>& frame,
                          const bool& even_parity);
    static bool crc32_check(std::vector<bool>& frame);
};
