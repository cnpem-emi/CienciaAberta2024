#include <button_control.hpp>

void setup () {
  Serial.begin(9600);
}

void loop() {
  readButtonMatrix();
}
