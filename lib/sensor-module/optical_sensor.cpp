#include "optical_sensor.hpp"

int sensor_state = 0;
int pulse_pin;

OpticalSensor::OpticalSensor(int sensor_pin, int sensor_output, int pulse_width, int mode) {
    // Configure sensor input
    this->sensor_pin = sensor_pin;
    pinMode(sensor_pin, INPUT_PULLUP);

    // Configure sensor output
    this->sensor_output = sensor_output;
    pulse_pin = this->sensor_output;
    pinMode(sensor_output, OUTPUT);

    this->pulse_width = pulse_width;

    // Configure sensor mode
    this->mode = mode;
}

void OpticalSensor::loop() {

    if(mode == AUTOMATIC_MODE && sensor_state == 1) {
        delay(this->pulse_width);
        digitalWrite(this->sensor_output, HIGH);
        sensor_state = 0;
    }
}

void OpticalSensor::sensor_callback(int sensor_state, int mode) {
    if(mode == AUTOMATIC_MODE && sensor_state == 1) {
        delay(this->pulse_width);
        digitalWrite(this->sensor_output, HIGH);
        sensor_state = 0;
        Serial.println(sensor_state);
    }
}

void OpticalSensor::config() {
    pinMode(this->sensor_output, OUTPUT);
    digitalWrite(this->sensor_output, HIGH);

    if(this->mode == AUTOMATIC_MODE) {
        attachInterrupt(digitalPinToInterrupt(this->sensor_pin), callPulse, CHANGE);
    }
}

void IRAM_ATTR callPulse() {
    digitalWrite(pulse_pin, LOW);
    sensor_state = 1;
}
