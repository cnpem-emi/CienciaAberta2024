#include "optical_sensor.hpp"
OpticalSensor sensor(4, AUTOMATIC_MODE);
#include "button_control.hpp"
//ButtonControl btn;

void setup () {
  Serial.begin(9600);
  sensor.config();
  //btn.config();
}

void loop() {
  //btn.readButtonMatrix();
  //sensor.read_sensor();
  sensor.loop();
}
