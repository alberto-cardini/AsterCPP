//
// Created by Alberto Cardini on 21/11/24.
//

#ifndef REDASTER_SPI_HPP
#define REDASTER_SPI_HPP

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx.h"

#ifdef __cplusplus
}
#endif

#include <memory>
#include <vector>
#include "iostream"
#include "Utils.hpp"
#include "Protocol.hpp"

class SPI : public Protocol{
public:
    explicit SPI(SPI_HandleTypeDef init, uint32_t polling_timeout = 0) : handler(std::make_unique<SPI_HandleTypeDef>(init)), polling_timeout(polling_timeout) {}

    HAL_StatusTypeDef Transmit(Identity role, Mode transmit_mode, std::vector<uint8_t>& buffer) const override;
    HAL_StatusTypeDef Receive(Identity role, Mode receive_mode, std::vector<uint8_t>& buffer) override;

private:
    std::unique_ptr<SPI_HandleTypeDef> handler;
    uint8_t polling_timeout;
};


#endif //REDASTER_SPI_HPP
