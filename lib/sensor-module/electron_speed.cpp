#include "electron_speed.hpp"

ElectronSpeed::ElectronSpeed(float radius) {
    float circunference;

    circunference = 2*3.14*radius;
    this->distance = circunference/6;
}

void ElectronSpeed::get_time(int sensor_id) {
    if (sensor_id != this->last_sensor_id) {
        this->last_sensor_id = sensor_id;
        this->last_time  = millis();
    }   
}

float ElectronSpeed::get_speed() {
    float delta_t;
    float speed;

    delta_t = (millis() - this->last_time)/1000;
    speed = this->distance/delta_t;

    return speed;
}
