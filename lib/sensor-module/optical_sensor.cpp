#include "optical_sensor.hpp"

int state = 0;

OpticalSensor::OpticalSensor(int sensor_pin, int mode) {
    this->sensor_pin = sensor_pin;
    pinMode(sensor_pin, INPUT_PULLUP);

    this->mode = mode;
}

void OpticalSensor::read_sensor() {
    //sensor_state = digitalRead(sensor_pin);
    sensor_state = analogReadMilliVolts(sensor_pin);

    switch (mode) {
    case MANUAL_MODE:
        sensor_callback(sensor_state, MANUAL_MODE);
        break;
    
    case AUTOMATIC_MODE:
        sensor_callback(sensor_state, AUTOMATIC_MODE);
        break;
    }
}

void OpticalSensor::sensor_callback(int sensor_state, int mode) {
    // Ler button_state
    // Iniciar timer
    // 

    //if (mode == AUTOMATIC_MODE && sensor_state >= 500) {
    //    pulseGenerator(21, 100);
    //    delay(50);
    //}
    //Serial.println(sensor_state);
}

void OpticalSensor::config() {
    //btn.config();
    pinMode(21, OUTPUT);
    digitalWrite(21, HIGH);

    attachInterrupt(digitalPinToInterrupt(4), callPulse, RISING);
}

void IRAM_ATTR callPulse() {
    pulseGenerator(21, 100);
    state = 1;
    //Serial.println("Interrupt!");
}

void OpticalSensor::loop() {
    if(state == 1) {
        delay(50);
        digitalWrite(21, HIGH);
        state = 0;
    }
}
