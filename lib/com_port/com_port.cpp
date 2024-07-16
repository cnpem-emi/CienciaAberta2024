#include "com_port.hpp"

void ComPort::config() {
    if (Serial.available() > 0){
        this->incoming_data = Serial.readString();
        Serial.write(0x01);
    }
}

void ComPort::getInfo() {
    doc["team name"] = "abc";
    doc["speed"] = this->speed;
    doc["laps"] = 0;
    doc["points"] = this->points;

    this->speed += 0.1;
    this->points += 2;
}

String ComPort::sendInfo() {
    return doc.as<String>();
}
