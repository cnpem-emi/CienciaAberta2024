#include "button_control.hpp"

ButtonControl::ButtonControl(int pulse_width) {
  this->pulse_width = pulse_width;
}

void ButtonControl::config() {
    for (int i = 0; i < numRow; i++) {
    pinMode(rowPin[i], OUTPUT);
    digitalWrite(rowPin[i], LOW);
  }

  for (int i = 0; i < numCol; i++) {
    pinMode(colPin[i], INPUT_PULLDOWN);
  }

  for (int i = 0; i < numRow * numCol; i++) {
    pinMode(pulsePin[i], OUTPUT);
    digitalWrite(pulsePin[i], PIN_STATE);
  }

  // Inicializa os tempos de debounce e os estados dos botões
  for (int row = 0; row < numRow; row++) {
    for (int col = 0; col < numCol; col++) {
      lastDebounceTime[row][col] = 0;
      lastButtonState[row][col] = LOW;
      buttonStates[row][col] = LOW;
    }
  }
}

void ButtonControl::readButtonMatrix() {
  for (int row = 0; row < numRow; row++) {
    // Ativa a linha atual
    digitalWrite(rowPin[row], HIGH);

    // Lê o estado das colunas
    for (int col = 0; col < numCol; col++) {
      bool reading = digitalRead(colPin[col]);

      // Se o estado do botão mudou
      if (reading != lastButtonState[row][col]) {
        lastDebounceTime[row][col] = millis();  // Atualiza o tempo de debounce
      }

      // Se o tempo de debounce passou
      if ((millis() - lastDebounceTime[row][col]) > DEBOUNCE_DELAY) {
        // Se o estado do botão mudou após o tempo de debounce
        if (reading != buttonStates[row][col]) {
          buttonStates[row][col] = reading;

          // Só age se o novo estado for HIGH (botão pressionado)
          if (buttonStates[row][col] == HIGH) {
            Serial.print("Button [");
            Serial.print(row);
            Serial.print("][");
            Serial.print(col);
            Serial.println("] pressed");

            // Calcula o índice do pino de pulso correspondente
            int pulsePinIndex = row * numCol + col;
            pulseGenerator(pulsePin[pulsePinIndex]);
            Serial.println("Pulso Gerado");
          }
        }
      }

      lastButtonState[row][col] = reading;  // Atualiza o último estado do botão
    }

    // Desativa a linha atual
    digitalWrite(rowPin[row], LOW);
  }
}

void ButtonControl::pulseGenerator(int pin) {
  digitalWrite(pin, HIGH);
  delay(this->pulse_width);
  digitalWrite(pin, LOW);
}
