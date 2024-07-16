#include "optical_sensor.hpp"

OpticalSensor::OpticalSensor(int sensor_pin, int sensor_output, int pulse_width, int mode) {
    // Configure sensor input
    this->sensor_pin = sensor_pin;
    pinMode(sensor_pin, INPUT_PULLDOWN);

    // Configure sensor output
    this->sensor_output = sensor_output;
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
    digitalWrite(SENSOR_3_OUTPUT, LOW);
    digitalWrite(SENSOR_4_OUTPUT, LOW);
    digitalWrite(SENSOR_5_OUTPUT, LOW);
    digitalWrite(SENSOR_6_OUTPUT, LOW);
}

void OpticalSensor::config() {
    pinMode(this->sensor_output, OUTPUT);
    digitalWrite(this->sensor_output, LOW);
}

void IRAM_ATTR callPulse_1() {
    digitalWrite(SENSOR_1_OUTPUT, HIGH);
    velocity.get_time(1);
}

void IRAM_ATTR callPulse_2() {
    digitalWrite(SENSOR_2_OUTPUT, HIGH);
    velocity.get_time(2);
}
void IRAM_ATTR callPulse_3() {
    digitalWrite(SENSOR_3_OUTPUT, HIGH);
    velocity.get_time(3);
}

void IRAM_ATTR callPulse_4() {
    digitalWrite(SENSOR_4_OUTPUT, HIGH);
    velocity.get_time(4);
}
void IRAM_ATTR callPulse_5() {
    digitalWrite(SENSOR_5_OUTPUT, HIGH);
    velocity.get_time(5);
}

void IRAM_ATTR callPulse_6() {
    digitalWrite(SENSOR_6_OUTPUT, HIGH);
    velocity.get_time(6);
}
