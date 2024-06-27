#ifndef BUTTON_CONTROL_HPP_
#define BUTTON_CONTROL_HPP_

#include <Arduino.h>

#define numRow  3
#define numCol 2
#define PIN_STATE HIGH
#define DEBOUNCE_DELAY 50  // Tempo de debounce em milissegundos

const int rowPin[] = {25, 26, 27}; //Pinos de entrada do sinal do pushbutton
const int colPin[] = {33, 32}; //Pinos de saída do sinal do pushbutton
const int pulsePin[]={21, 19, 18, 5, 17, 16}; //Pinos de geração de pulso

unsigned long lastDebounceTime[numRow][numCol];  // Guarda o último tempo de debounce
bool lastButtonState[numRow][numCol];  // Guarda o último estado do botão
bool buttonStates[numRow][numCol];  // Guarda o estado atual do botão

void pulseGenerator(int pin, int durationPulse); // Declaração do protótipo da função

void configButton();
void readButtonMatrix();
#endif // BUTTON_CONTROL_HPP_