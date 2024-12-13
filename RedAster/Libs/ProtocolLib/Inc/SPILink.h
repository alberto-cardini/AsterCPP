//
// Created by danie on 13/12/2024.
//

#ifndef SPILINK_H
#define SPILINK_H


#include "Link.h"
#include "SPIChannel.hpp"

class SPILink : public Link{
public:
    SPILink(SPIChannel& channel, GPIO_TypeDef* csPort, uint16_t csPin, Mode modeTransmit)
        : spiChannel(channel), csPort(csPort), csPin(csPin) {
        status = HAL_OK;
        modeTransmit = modeTransmit;
    }

    /*
     * @brief: Allow to transmit data to the e2e connection
     * @param: Buffer to transmit.
     *
     * @retval: HAL status.
     */
    HAL_StatusTypeDef Transmit(std::vector<uint8_t> &buffer);

private:
    SPIChannel& spiChannel;
    GPIO_TypeDef* csPort;
    uint16_t csPin;

    void selectChip() const;
    void deselectChip() const;
};



#endif //SPILINK_H
