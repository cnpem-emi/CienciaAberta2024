#include "button_control.hpp"
#include "electron_speed.hpp"
#include "optical_sensor.hpp"

extern ElectronSpeed velocity;

OpticalSensor sensor1(SENSOR_1_PIN, SENSOR_1_OUTPUT, 20, AUTOMATIC_MODE);
OpticalSensor sensor2(SENSOR_2_PIN, SENSOR_2_OUTPUT, 10, AUTOMATIC_MODE);

//ButtonControl btn(50);

void setup () {
  Serial.begin(9600);
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
}

// #include <Arduino.h>
// #include "com_port.hpp"
// #include "electron_speed.hpp"

// extern ElectronSpeed velocity;
// ComPort serial;
// String json;

// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
//   if (serial.send_data == false) {
//     serial.config();
//   }
//   else if (serial.send_data == true) {
//     serial.getInfo(velocity);
//     json = serial.sendInfo();
//     Serial.println(json);
//   }
//   delay(1);
// }
