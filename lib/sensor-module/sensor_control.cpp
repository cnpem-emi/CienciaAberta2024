#include "sensor_control.hpp"

SensorControl::SensorControl(int pulse_width, int mode) {
    this->pulse_width = pulse_width;
    this->mode = mode;
}

void SensorControl::config() {
    sensor_1.config();
    sensor_2.config();

    if(mode == AUTOMATIC_MODE) {
        attachInterrupt(digitalPinToInterrupt(SENSOR_1_PIN), callPulse_1, CHANGE);
        attachInterrupt(digitalPinToInterrupt(SENSOR_2_PIN), callPulse_2, CHANGE);
    }
}

void SensorControl::loop() {
    sensor_1.loop();
    sensor_2.loop();
}
