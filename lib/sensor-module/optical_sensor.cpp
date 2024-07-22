#include "optical_sensor.hpp"

ElectronSpeed velocity(1);

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
        //asm volatile ("nop"::);
        //digitalWrite(this->sensor_output, LOW);
        GPIO.out_w1tc = (1 << this->sensor_output);
        velocity.get_time(sensor_pin);
    }
    //digitalWrite(SENSOR_1_OUTPUT, LOW);
    // digitalWrite(SENSOR_2_OUTPUT, LOW);
    // digitalWrite(SENSOR_3_OUTPUT, LOW);
    // digitalWrite(SENSOR_4_OUTPUT, LOW);
    // digitalWrite(SENSOR_5_OUTPUT, LOW);
    // digitalWrite(SENSOR_6_OUTPUT, LOW);
}

void OpticalSensor::config() {
    // pinMode(this->sensor_output, OUTPUT);
    // digitalWrite(this->sensor_output, LOW);
    gpio_config_t io_conf;

    io_conf.mode = GPIO_MODE_OUTPUT;

    io_conf.pin_bit_mask = (1 << SENSOR_1_OUTPUT) | 
        (1 << SENSOR_2_OUTPUT) | 
        (1 << SENSOR_3_OUTPUT) |
        (1 << SENSOR_4_OUTPUT) | 
        (1 << SENSOR_5_OUTPUT) | 
        (1 << SENSOR_6_OUTPUT);

    gpio_config(&io_conf);
}

void IRAM_ATTR callPulse_1() {
    //digitalWrite(SENSOR_1_OUTPUT, HIGH);
    GPIO.out_w1ts = (1 << SENSOR_1_OUTPUT);
}

void IRAM_ATTR callPulse_2() {
    //digitalWrite(SENSOR_2_OUTPUT, HIGH);
    GPIO.out_w1ts = (1 << SENSOR_2_OUTPUT);
}
void IRAM_ATTR callPulse_3() {
    //digitalWrite(SENSOR_3_OUTPUT, HIGH);
    GPIO.out_w1ts = (1 << SENSOR_3_OUTPUT);
}

void IRAM_ATTR callPulse_4() {
    //digitalWrite(SENSOR_4_OUTPUT, HIGH);
    GPIO.out_w1ts = (1 << SENSOR_4_OUTPUT);
}

void IRAM_ATTR callPulse_5() {
    //digitalWrite(SENSOR_5_OUTPUT, HIGH);
    GPIO.out_w1ts = (1 << SENSOR_5_OUTPUT);
}

void IRAM_ATTR callPulse_6() {
    //digitalWrite(SENSOR_6_OUTPUT, HIGH);
    GPIO.out_w1ts = (1 << SENSOR_6_OUTPUT);
}
