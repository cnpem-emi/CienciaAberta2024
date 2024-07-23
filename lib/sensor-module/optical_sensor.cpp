#include "optical_sensor.hpp"

ElectronSpeed velocity(0.45);

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

    if(mode == MANUAL_MODE && digitalRead(sensor_pin) == HIGH) {
        velocity.get_time(sensor_pin);
    }

    if(mode == AUTOMATIC_MODE && digitalRead(sensor_pin) == HIGH) {
        delay(this->pulse_width);
        GPIO.out_w1tc = (1 << this->sensor_output);
        
        if (velocity.last_sensor_id != sensor_pin && velocity.last_time != 0) {
            this->measure_speed = true;
            velocity.last_sensor_id = this->sensor_pin;
        }
        if (this->measure_speed != true) velocity.get_time(sensor_pin);
    }
}

void OpticalSensor::config() {
    gpio_config_t io_conf;

    io_conf.mode = GPIO_MODE_OUTPUT;

    io_conf.pin_bit_mask = (1 << this->sensor_output);

    gpio_config(&io_conf);
}

void IRAM_ATTR callPulse_1() {
    GPIO.out_w1ts = (1 << SENSOR_1_OUTPUT);
}

void IRAM_ATTR callPulse_2() {
    GPIO.out_w1ts = (1 << SENSOR_2_OUTPUT);
}

void IRAM_ATTR callPulse_3() {
    GPIO.out_w1ts = (1 << SENSOR_3_OUTPUT);
}

void IRAM_ATTR callPulse_4() {
    GPIO.out_w1ts = (1 << SENSOR_4_OUTPUT);
}

void IRAM_ATTR callPulse_5() {
    GPIO.out_w1ts = (1 << SENSOR_5_OUTPUT);
}

void IRAM_ATTR callPulse_6() {
    GPIO.out_w1ts = (1 << SENSOR_6_OUTPUT);
}
