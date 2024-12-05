//
// Created by Alberto Cardini on 21/11/24.
//

#ifndef REDASTER_PROTOCOL_HPP
#define REDASTER_PROTOCOL_HPP

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx.h"

#ifdef __cplusplus
}
#endif

#include "Utils.hpp"

class Protocol {
    virtual HAL_StatusTypeDef Transmit(Identity role, Mode transmit_mode, std::vector<uint8_t>& outgoing_buffer) const = 0;
    virtual HAL_StatusTypeDef Receive(Identity role, Mode transmit_mode, std::vector<uint8_t>& incoming_buffer) = 0;
};

#endif //REDASTER_PROTOCOL_HPP