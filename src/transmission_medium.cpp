#include "../include/transmission_medium.hpp"

TransmissionMedium::TransmissionMedium(int error_likelihood) 
    : error_likelihood_ { error_likelihood } {}

std::vector<bool> TransmissionMedium::receive(const TransportLayer& ttl)
{

}

void TransmissionMedium::send(const std::vector<bool>& frame, const TransportLayer& rtl)
{

}

void TransmissionMedium::disturb(std::vector<bool>& frame) {
    if(rand() % 100 > error_likelihood_) {
        int index = (rand() % frame.size()) - 1;

        frame[index] = !frame[index];
    }
}