#ifndef _COM_PORT_HPP_
#define _COM_PORT_HPP_

#include <Arduino.h>
#include <ArduinoJson.h>
#include "electron_speed.hpp"

class ComPort {
    public:
        bool send_data = false;
        
        void config();

        void getInfo(ElectronSpeed &velocity);

        String sendInfo();

    private:
        float speed = 0;
        String incoming_data;
        
        JsonDocument doc;
};

#endif  // _COM_PORT_HPP_
