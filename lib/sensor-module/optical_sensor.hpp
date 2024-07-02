#ifndef _OPTICAL_SENSOR_HPP_
#define _OPTICAL_SENSOR_HPP_

#include <Arduino.h>
#include <vector>
#include "button_control.hpp"

#define MANUAL_MODE 1
#define AUTOMATIC_MODE 2

class OpticalSensor {
    public:
        int sensor_output;
        int pulse_width;

        // Configures the pins used for the sensor.
        OpticalSensor(int sensor_pin, int sensor_output, int pulse_width, int mode);

        // Configures the interrupt. Must be called at "void setup()".
        void config();

        // Sensor main loop.
        void loop();
    
    private:
        int sensor_pin;
        int mode;

        // Callback function that depends on the operation mode of the sensor.
        void sensor_callback(int button_state, int mode);
};

void IRAM_ATTR callPulse();

#endif  // _OPTICAL_SENSOR_HPP_
