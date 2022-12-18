#pragma once
// STD includes
#include <string>
#include <vector>

/**
 * @brief The application layer of the network
 */
class ApplicationLayer
{
public:
    ApplicationLayer(void) = default;
    /**
     * @brief Constructs an application layer with an specified identification
     * @param id The id of the application layer - it will be used to differentiate 
     * between the transmiter and the reception application layer
     */
    ApplicationLayer(const std::string& id);

    /**
     * @brief Given a message, transmits it to the data link layer
     * @param message The message to be transmited
     */ 
    void send(const std::string& message, const DLL& dll);

    /**
     * @brief Interface between the application and the link layers responsabel
     * to receive frames from the latter
     * @param frame The message received as a bit set
     * @return string The message received as a string
     */
    std::string receive(const std::vector<bool> frame);

    /**
     * @brief Assigns a value to the attribute id_
     * @param id The value to be assigned
     */
    void id(const std::string& id);

    /**
     * @brief Gets the value of the id_ attribute
     * @return string The value of the id_ attribute
     */
    const std::string& id(void);

private:
    std::string id_;

};
