#include "com_port.hpp"

void ComPort::config() {
    if (Serial.available() > 0){
        this->incoming_data = Serial.readString();
        Serial.write(0x01);
    }
}

void ComPort::getInfo(ElectronSpeed &velocity) {
    doc["speed"] = velocity.get_speed();
    doc["laps"] = 0;
}

String ComPort::sendInfo() {
    return doc.as<String>();
}
