#include <button_control.hpp>

ButtonControl btn;

void setup () {
  Serial.begin(9600);
  btn.config();
}

void loop() {
  btn.readButtonMatrix();
}
