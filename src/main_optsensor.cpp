#include "optical_sensor.hpp"

OpticalSensor sensor(2, MANUAL_MODE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensor.read_sensor();
}