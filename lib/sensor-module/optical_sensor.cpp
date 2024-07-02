#include "optical_sensor.hpp"

OpticalSensor::OpticalSensor(int sensor_pin, int sensor_output, int pulse_width, int mode) {
    // Configure sensor input
    this->sensor_pin = sensor_pin;
    pinMode(sensor_pin, INPUT_PULLDOWN);

    // Configure sensor output
    this->sensor_output = sensor_output;
    pulse_pin = this->sensor_output;
    pinMode(sensor_output, OUTPUT);

    this->pulse_width = pulse_width;

    // Configure sensor mode
    this->mode = mode;
}

void OpticalSensor::loop() {
    
    if(mode == AUTOMATIC_MODE && digitalRead(sensor_pin) == HIGH) {
        delay(this->pulse_width);
        digitalWrite(this->sensor_output, LOW);
    }

    digitalWrite(SENSOR_1_OUTPUT, LOW);
    digitalWrite(SENSOR_2_OUTPUT, LOW);
}

void OpticalSensor::config() {
    pinMode(this->sensor_output, OUTPUT);
    digitalWrite(this->sensor_output, LOW);
}

void IRAM_ATTR callPulse_1() {
    digitalWrite(SENSOR_1_OUTPUT, HIGH);
}

void IRAM_ATTR callPulse_2() {
    digitalWrite(SENSOR_2_OUTPUT, HIGH);
}
