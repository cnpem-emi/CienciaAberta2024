//#include "optical_sensor.hpp"
//#include "button_control.hpp"
#include "sensor_control.hpp"

//OpticalSensor sensor1(4, 21, 20, AUTOMATIC_MODE);
//OpticalSensor sensor2(15, 19, 20, AUTOMATIC_MODE);

//ButtonControl btn(50);

SensorControl sc(20, AUTOMATIC_MODE);

void setup () {
  Serial.begin(9600);
  sc.config();
  //sensor1.config();
  //sensor2.config();
  //btn.config();
}

void loop() {
  //btn.readButtonMatrix();
  //sensor1.loop();
  //sensor2.loop();
  sc.loop();
}
