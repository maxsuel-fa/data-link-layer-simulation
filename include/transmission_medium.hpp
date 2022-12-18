#include <vector>

/**
 * @brief The transmission medium of the network
 */
class TransmissionMedium
{
public:
    TransmissionMedium(void) = default;

    /**
     * @brief Send a frame to the receiver transport layer
     * @param frame The frame to be sent
     */
    static void send(std::vector<bool>& frame);

    /**
     * @brief Disturbs some bit of the frame according to the likelihood
     * @param frame The frame of bits to be disturbed
     * @param error_likelihood The error likelihood
     */
    static void disturb(std::vector<bool>& frame, const int& error_likelihood);
};
