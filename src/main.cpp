#include "button_control.hpp"
#include "electron_speed.hpp"
#include "optical_sensor.hpp"
#include "com_port.hpp"

extern ElectronSpeed velocity;

ComPort serial;
String json;

OpticalSensor sensor1(SENSOR_1_PIN, SENSOR_1_OUTPUT, 20, AUTOMATIC_MODE);
OpticalSensor sensor2(SENSOR_2_PIN, SENSOR_2_OUTPUT, 10, AUTOMATIC_MODE);
OpticalSensor sensor3(SENSOR_3_PIN, SENSOR_3_OUTPUT, 20, AUTOMATIC_MODE);

//ButtonControl btn(50);

int last_sensor = 0;

void setup () {
  Serial.begin(9600);
  sensor1.config();
  sensor2.config();
  sensor3.config();
  attachInterrupt(digitalPinToInterrupt(SENSOR_1_PIN), callPulse_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_2_PIN), callPulse_2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_3_PIN), callPulse_3, CHANGE);
  //btn.config();
}

void loop() {
  //btn.readButtonMatrix();
  sensor1.loop();
  sensor2.loop();
  sensor3.loop();
  if (sensor1.measure_speed == true || sensor2.measure_speed == true || sensor3.measure_speed == true){
    serial.getInfo(velocity.get_speed());
    json = serial.sendInfo();
    Serial.println(json);
    //Serial.println(velocity.last_time);
    sensor1.measure_speed = false;
    sensor2.measure_speed = false;
    sensor3.measure_speed = false;
  }
  
  GPIO.out_w1tc = (1 << SENSOR_1_OUTPUT);
  GPIO.out_w1tc = (1 << SENSOR_2_OUTPUT);
  GPIO.out_w1tc = (1 << SENSOR_3_OUTPUT);
  GPIO.out_w1tc = (1 << SENSOR_4_OUTPUT);
  GPIO.out_w1tc = (1 << SENSOR_5_OUTPUT);
  GPIO.out_w1tc = (1 << SENSOR_6_OUTPUT);
}
