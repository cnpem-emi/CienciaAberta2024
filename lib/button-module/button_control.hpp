#ifndef BUTTON_CONTROL_HPP_
#define BUTTON_CONTROL_HPP_

#include <Arduino.h>

#define numRow 3
#define numCol 2
#define PIN_STATE LOW
#define DEBOUNCE_DELAY 50  // Tempo de debounce em milissegundos

class ButtonControl {
    public:
        void config();
        void readButtonMatrix();

        ButtonControl(int pulse_width);

    private:
        int pulse_width;

        const int rowPin[3] = {25, 26, 27}; //Pinos de entrada do sinal do pushbutton
        const int colPin[2] = {33, 32}; //Pinos de saída do sinal do pushbutton
        const int pulsePin[6] = {16, 19, 18, 5, 17, 21}; //Pinos de geração de pulso

        unsigned long lastDebounceTime[numRow][numCol];  // Guarda o último tempo de debounce
        bool lastButtonState[numRow][numCol];  // Guarda o último estado do botão
        bool buttonStates[numRow][numCol];  // Guarda o estado atual do botão

        void pulseGenerator(int pin);
};

#endif // BUTTON_CONTROL_HPP_
