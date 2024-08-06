#include "com_port.hpp"

void ComPort::config() {
    Serial.println("ESP 32 trying to connect witbhh the GUI...");
    delay(200);
    if (Serial.available() > 0){
        this->incoming_data = Serial.readString();
        Serial.write(0x01);
    }
}

void ComPort::getInfo(float speed) {
    doc["speed"] = speed;
}

void ComPort::sendInfo() {
    // delay(1);
    // serializeJson(doc, Serial);
    // return doc.as<String>();
    Serial.println(doc["speed"].as<float>());
}
