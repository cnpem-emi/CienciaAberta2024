#include "optical_sensor.hpp"

OpticalSensor::OpticalSensor(int sensor_pin, int mode) {
    this->sensor_pin = sensor_pin;
    pinMode(sensor_pin, INPUT_PULLUP);

    this->mode = mode;
}

void OpticalSensor::read_sensor() {
    button_state = digitalRead(sensor_pin);

    switch (mode) {
    case MANUAL_MODE:
        sensor_callback(button_state, MANUAL_MODE);
        break;
    
    case AUTOMATIC_MODE:
        sensor_callback(button_state, AUTOMATIC_MODE);
        break;
    }
}

void OpticalSensor::sensor_callback(int button_state, int mode) {
    // Ler button_state
    // Iniciar timer
    // 
    Serial.println(button_state);
}
