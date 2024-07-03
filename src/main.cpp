//#include "optical_sensor.hpp"
#include "button_control.hpp"
#include "sensor_control.hpp"

OpticalSensor sensor1(SENSOR_1_PIN, SENSOR_1_OUTPUT, 20, AUTOMATIC_MODE);
OpticalSensor sensor2(SENSOR_2_PIN, SENSOR_2_OUTPUT, 20, AUTOMATIC_MODE);

//ButtonControl btn(50);

//SensorControl sc(10, AUTOMATIC_MODE);

void setup () {
  Serial.begin(9600);
  //sc.config();
  sensor1.config();
  sensor2.config();
  attachInterrupt(digitalPinToInterrupt(SENSOR_1_PIN), callPulse_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_2_PIN), callPulse_2, CHANGE);
  //btn.config();
}

void loop() {
  //btn.readButtonMatrix();
  sensor1.loop();
  sensor2.loop();
  //sc.loop();
}
