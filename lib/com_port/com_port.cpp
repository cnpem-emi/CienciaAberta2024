#include "com_port.hpp"

void ComPort::config() {
    Serial.println("ESP 32 trying to connect witbhh the GUI...");
    if (Serial.available() > 0){
        this->incoming_data = Serial.readString();
        Serial.write(0x01);
    }
}

void ComPort::getInfo(float speed) {
    doc["speed"] = speed;
}

String ComPort::sendInfo() {
    return doc.as<String>();
}
