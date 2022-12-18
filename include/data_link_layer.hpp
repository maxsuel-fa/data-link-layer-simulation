#pragma once
// STD includes
#include <string>
#include <vector>

/**
 * @brief The data link layer of the network
 */
class DLL
{
public:
    DLL(void) = default;

    /**
     * @brief Constructs a data link layer with an specified identification
     * @param id The id of the data link layer - it will be used to differentiate
     * between the transmiter and the receptor data link layer
     */
    DLL(const std::string& id);

    /**
     * @brief Given a frame, transmits it to the transport layer
     * @param frame The frame to be transmited
     */
    void send(const std::vector<bool> frame);

    /**
     * @brief Interface between the data link and the transport layers
     * @param frame The message received from the transport layer as a bit set
     */
    void receive(const std::vector<bool> frame);

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

    void add_checker(std::vector<bool>& frame);
    void add_parity_checkbit(std::vector<bool>& frame,
                             const bool& even_parity = true);
    void add_crc32_check(std::vector<bool>& frame);
    void crc32_check(std::vector<bool>& frame);
};
