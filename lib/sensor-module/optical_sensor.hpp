#ifndef _OPTICAL_SENSOR_HPP_
#define _OPTICAL_SENSOR_HPP_

#include <Arduino.h>
#include "button_control.hpp"
#include "electron_speed.hpp"

#define MANUAL_MODE 1
#define AUTOMATIC_MODE 2

#define SENSOR_1_PIN 4
#define SENSOR_2_PIN 5
#define SENSOR_3_PIN 2
#define SENSOR_4_PIN 7
#define SENSOR_5_PIN 8
#define SENSOR_6_PIN 9

#define SENSOR_1_OUTPUT 21
#define SENSOR_2_OUTPUT 19
#define SENSOR_3_OUTPUT 15
#define SENSOR_4_OUTPUT 16
#define SENSOR_5_OUTPUT 17
#define SENSOR_6_OUTPUT 18

class OpticalSensor {
    public:
        int sensor_output;
        int pulse_width;
        int sensor_pin;
        bool measure_speed = false;

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
void IRAM_ATTR callPulse_3();
void IRAM_ATTR callPulse_4();
void IRAM_ATTR callPulse_5();
void IRAM_ATTR callPulse_6();

#endif  // _OPTICAL_SENSOR_HPP_
