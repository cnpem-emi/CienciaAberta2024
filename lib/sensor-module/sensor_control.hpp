#ifndef _SENSOR_CONTROL_HPP_
#define _SENSOR_CONTROL_HPP_

#include "optical_sensor.hpp"

class SensorControl {
    public:
        int mode;
        int pulse_width;
        
        void config();

        void loop();

        SensorControl(int pulse_width, int mode);
    
    private:
        OpticalSensor sensor_1 = OpticalSensor(SENSOR_1_PIN, SENSOR_1_OUTPUT, pulse_width, this->mode);
        OpticalSensor sensor_2 = OpticalSensor(SENSOR_2_PIN, SENSOR_2_OUTPUT, pulse_width, this->mode);
};

#endif  // _SENSOR_CONTROL_HPP_
