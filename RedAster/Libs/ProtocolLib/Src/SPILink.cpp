//
// Created by danie on 13/12/2024.
//

#include "SPILink.h"


HAL_StatusTypeDef SPILink::Transmit(std::vector<uint8_t> &buffer) {
    selectChip();       // Abilita CS
    status = spiChannel.Transmit(Identity::N_A, Mode::POLLING, buffer);
    deselectChip();     // Disabilita CS
    return status;
}

void SPILink::selectChip() {
    HAL_GPIO_WritePin(csPort, csPin, GPIO_PIN_RESET);   // CS low
}

void SPILink::deselectChip() {
    HAL_GPIO_WritePin(csPort, csPin, GPIO_PIN_SET);     // CS high
}