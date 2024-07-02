#ifndef _OPTICAL_SENSOR_HPP_
#define _OPTICAL_SENSOR_HPP_

#include <Arduino.h>
#include <vector>
#include "button_control.hpp"

#define MANUAL_MODE 1
#define AUTOMATIC_MODE 2

#define SENSOR_1_PIN 4
#define SENSOR_2_PIN 2

#define SENSOR_1_OUTPUT 21
#define SENSOR_2_OUTPUT 19

class OpticalSensor {
    public:
        int sensor_output;
        int pulse_width;
        int sensor_pin;

        // Configures the pins used for the sensor.
        OpticalSensor(int sensor_pin, int sensor_output, int pulse_width, int mode);

        // Configures the interrupt. Must be called at "void setup()".
        void config();

        // Sensor main loop.
        void loop();
    
    private:
        int mode;
};

void IRAM_ATTR callPulse_1();
void IRAM_ATTR callPulse_2();

#endif  // _OPTICAL_SENSOR_HPP_
