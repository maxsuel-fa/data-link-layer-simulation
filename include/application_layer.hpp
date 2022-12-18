#pragma once
// STD includes
#include <string>
#include <vector>

// Local library includes
#include "data_link_layer.hpp"
/**
 * @brief The application layer of the network
 */
class ApplicationLayer
{
public:
    ApplicationLayer(void) = default;

    /**
     * @brief Given a message, transmits it to the data link layer
     * @param message The message to be transmited
     */ 
    static void send(const std::string& message);

    /**
     * @brief Interface between the application and the link layers responsabel
     * to receive frames from the latter
     * @param frame The message received as a bit set
     */
    static void receive(std::vector<bool>& frame);
};
