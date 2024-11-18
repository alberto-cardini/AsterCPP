/*
 * Sensor.h
 *
 *  Created on: Nov 18, 2024
 *      Author: danie
 */

#ifndef SENSORSLIB_SENSOR_H_
#define SENSORSLIB_SENSOR_H_

class Sensor {
public:
    virtual ~Sensor() = default;
    virtual void readData() = 0;
    virtual void writeData() = 0;
};

#endif /* SENSORSLIB_SENSOR_H_ */
