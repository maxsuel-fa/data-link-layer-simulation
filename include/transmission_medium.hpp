#include <vector>

/**
 * @brief The transmission medium of the network
 */
class TransmissionMedium
{
public:
    /**
     * @brief Constructs a transmission medium w/ the error proneness given by
     * likelihood
     * @param error_likelihood The likelihood of this transmission medium to
     * commit an error
     */
    TransmissionMedium(int error_likelihood);

    /**
     * @brief Receives a frame coming from the transmitter transport layer
     * @param ttl The transmitter transport layer, responsible for sending the
     * message to this transmission medium
     */
    std::vector<bool> receive(const TransportLayer& ttl);

    /**
     * @brief Send a frame to the receiver transport layer
     * @param frame The frame to be sent
     * @param rtl The receiver transport layer
     */
    void send(const std::vector<bool>& frame, const TransportLayer& rtl);

    /**
     * @brief Disturbs some bit of the frame according to the likelihood
     * @param frame The frame of bits to be disturbed
     */
    void disturb(std::vector<bool>& frame);
private:
    int error_likelihood_;
};