#ifndef _COM_PORT_HPP_
#define _COM_PORT_HPP_

#include <Arduino.h>
#include <ArduinoJson.h>

class ComPort {
    public:
        bool send_data = false;
        
        void config();

        void getInfo();

        String sendInfo();

    private:
        float speed = 0;
        float points = 0;
        String incoming_data;
        
        JsonDocument doc;
};

#endif  // _COM_PORT_HPP_
