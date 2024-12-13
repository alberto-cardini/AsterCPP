//
// Created by danie on 13/12/2024.
//

#ifndef LINK_H
#define LINK_H

#include "SPIChannel.hpp"
#include <cstdint>

class Link{

protected:
    HAL_StatusTypeDef status;
    Mode modeTransmit;

public:
    virtual ~Link() = default;
    virtual void Transmit() = 0;
};

#endif // CONNECTION_H