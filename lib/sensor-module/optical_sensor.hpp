#ifndef _SENSOR_CONTROL_HPP_
#define _SENSOR_CONTROL_HPP_

#include <Arduino.h>

#define MANUAL_MODE 1
#define AUTOMATIC_MODE 2

class OpticalSensor {
    public:
        // Configures the pin used for the sensor.
        OpticalSensor(int sensor_pin, int mode);

        // Reads the sensor and returns the sensor state.
        void read_sensor();
    
    private:
        int sensor_pin;
        int button_state = 0;
        int mode;

        // Callback function that depends on the operation mode of the sensor.
        void sensor_callback(int button_state, int mode);
};

#endif  // _SENSOR_CONTROL_HPP_
