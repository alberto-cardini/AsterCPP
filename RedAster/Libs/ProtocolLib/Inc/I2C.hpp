//
// Created by Alberto Cardini on 21/11/24.
//

#ifndef REDASTER_I2C_HPP
#define REDASTER_I2C_HPP

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx.h"

#ifdef __cplusplus
}
#endif

#include <memory>
#include <vector>
#include "Protocol.hpp"
#include "Utils.hpp"

class I2C : public Protocol{
public:
    explicit I2C(I2C_HandleTypeDef init, uint32_t polling_timeout = 0) : handler(std::make_unique<I2C_HandleTypeDef>(init)), polling_timeout(polling_timeout) {}

    HAL_StatusTypeDef Transmit(Identity role, Mode transmit_mode, std::vector<uint8_t>& buffer) const override;
    HAL_StatusTypeDef Receive(Identity role, Mode receive_mode, std::vector<uint8_t>& buffer) override;

private:
    std::unique_ptr<I2C_HandleTypeDef> handler;
    uint8_t polling_timeout;
};

#endif //REDASTER_I2C_HPP
