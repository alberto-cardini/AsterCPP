//
// Created by danie on 13/12/2024.
//

#ifndef SPILINK_H
#define SPILINK_H


#include "SPIChannel.hpp"

class SPILink {
public:
    SPILink(SPIChannel& channel, GPIO_TypeDef* csPort, uint16_t csPin)
        : spiChannel(channel), csPort(csPort), csPin(csPin) {
        status = HAL_OK;
    }

    HAL_StatusTypeDef Transmit(std::vector<uint8_t> &buffer);

private:
    SPIChannel& spiChannel;
    GPIO_TypeDef* csPort;
    uint16_t csPin;
    HAL_StatusTypeDef status;

    void selectChip();
    void deselectChip();
};



#endif //SPILINK_H
