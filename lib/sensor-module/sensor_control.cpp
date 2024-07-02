#include "sensor_control.hpp"

SensorControl::SensorControl(int pulse_width, int mode) {
    this->pulse_width = pulse_width;
    this->mode = mode;
}

void SensorControl::createSensorList() {
    
}

void SensorControl::config() {
    sensor_1.config();
    //sensor_2.config();
}

void SensorControl::loop() {
    sensor_1.loop();
    //sensor_2.loop();
}
