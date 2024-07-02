#ifndef _SENSOR_CONTROL_HPP_
#define _SENSOR_CONTROL_HPP_

#include "optical_sensor.hpp"

#define SENSOR_1_PIN 4
#define SENSOR_2_PIN 2

#define SENSOR_1_OUTPUT 21
#define SENSOR_2_OUTPUT 22

class SensorControl {
    public:
        void config();

        void loop();

        SensorControl(int pulse_width, int mode);
    
    private:
        int mode;
        int pulse_width;

        std::vector<OpticalSensor> sensorList;

        void createSensorList();

        OpticalSensor sensor_1 = OpticalSensor(SENSOR_1_PIN, SENSOR_1_OUTPUT, pulse_width, mode);
        OpticalSensor sensor_2 = OpticalSensor(SENSOR_2_PIN, SENSOR_2_OUTPUT, pulse_width, mode);
};

#endif  // _SENSOR_CONTROL_HPP_
