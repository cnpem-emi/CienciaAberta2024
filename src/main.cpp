#include "button_control.hpp"
#include "electron_speed.hpp"
#include "optical_sensor.hpp"
#include "com_port.hpp"

#define PULSE_WIDTH_MS 10
extern ElectronSpeed velocity;

ComPort serial;
String json;

OpticalSensor sensor1(SENSOR_1_PIN, SENSOR_1_OUTPUT, PULSE_WIDTH_MS, AUTOMATIC_MODE);
OpticalSensor sensor2(SENSOR_2_PIN, SENSOR_2_OUTPUT, PULSE_WIDTH_MS, AUTOMATIC_MODE);
OpticalSensor sensor3(SENSOR_3_PIN, SENSOR_3_OUTPUT, PULSE_WIDTH_MS, AUTOMATIC_MODE);
OpticalSensor sensor4(SENSOR_4_PIN, SENSOR_4_OUTPUT, PULSE_WIDTH_MS, AUTOMATIC_MODE);
OpticalSensor sensor5(SENSOR_5_PIN, SENSOR_5_OUTPUT, PULSE_WIDTH_MS, AUTOMATIC_MODE);
OpticalSensor sensor6(SENSOR_6_PIN, SENSOR_6_OUTPUT, PULSE_WIDTH_MS, AUTOMATIC_MODE);

ButtonControl btn(50);

void setup () {
  Serial.begin(9600);
  sensor1.config();
  sensor2.config();
  sensor3.config();
  sensor4.config();
  sensor5.config();
  sensor6.config();
  attachInterrupt(digitalPinToInterrupt(SENSOR_1_PIN), callPulse_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_2_PIN), callPulse_2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_3_PIN), callPulse_3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_4_PIN), callPulse_4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_5_PIN), callPulse_5, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_6_PIN), callPulse_6, CHANGE);
  // btn.config();
}

void loop() {
  // if (serial.send_data == false) {
  //   serial.config();
  // } else {
  // btn.readButtonMatrix();
  sensor1.loop();
  sensor2.loop();
  sensor3.loop();
  sensor4.loop();
  sensor5.loop();
  sensor6.loop();
  
  if (sensor1.measure_speed == true || sensor2.measure_speed == true || sensor3.measure_speed == true ||
      sensor4.measure_speed == true || sensor5.measure_speed == true || sensor6.measure_speed == true){
    serial.getInfo(velocity.get_speed());
    json = serial.sendInfo();
    Serial.println(json);

    sensor1.measure_speed = false;
    sensor2.measure_speed = false;
    sensor3.measure_speed = false;
    sensor4.measure_speed = false;
    sensor5.measure_speed = false;
    sensor6.measure_speed = false;
    }
    
    GPIO.out_w1tc = (1 << SENSOR_1_OUTPUT);
    GPIO.out_w1tc = (1 << SENSOR_2_OUTPUT);
    GPIO.out_w1tc = (1 << SENSOR_3_OUTPUT);
    GPIO.out_w1tc = (1 << SENSOR_4_OUTPUT);
    GPIO.out_w1tc = (1 << SENSOR_5_OUTPUT);
    GPIO.out_w1tc = (1 << SENSOR_6_OUTPUT);
  }

