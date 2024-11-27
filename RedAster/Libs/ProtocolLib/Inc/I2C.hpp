//
// Created by Alberto Cardini on 21/11/24.
//

#ifndef REDASTER_I2C_HPP
#define REDASTER_I2C_HPP

//the include section in empty for the moment due to the fact that the pin config has not been done yet
#include "../../Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_i2c.h"
#include <memory>
#include <vector>
#include "iostream"

enum class Mode {
    NON_BLOCKING, POLLING
}typedef Mode;

enum class Identity {
    MASTER, SLAVE
}typedef Identity;

class I2C {
public:
    explicit I2C(I2C_HandleTypeDef init) : parameters(std::make_unique<I2C_HandleTypeDef>(init)) {}

    HAL_StatusTypeDef Transmit(Identity role, Mode transmit_mode, std::vector<uint8_t> data, uint8_t timeout);
    HAL_StatusTypeDef Receive(Identity role, Mode receive_mode, );

private:
    std::unique_ptr<I2C_HandleTypeDef> parameters;
    uint8_t polling_timeout;
};


#endif //REDASTER_I2C_HPP
