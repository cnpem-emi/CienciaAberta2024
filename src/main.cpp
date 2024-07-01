#include "optical_sensor.hpp"
OpticalSensor sensor1(4, 21, 20, AUTOMATIC_MODE);
OpticalSensor sensor2(2, 18, 20, AUTOMATIC_MODE);
//#include "button_control.hpp"
//ButtonControl btn;

//#include "sensor_control.hpp"

//SensorControl sc(100, AUTOMATIC_MODE);

void setup () {
  Serial.begin(9600);
  //sc.config();
  sensor1.config();
  sensor2.config();
  //btn.config();
}

void loop() {
  //btn.readButtonMatrix();
  sensor1.loop();
  sensor2.loop();
  //sc.loop();
}
