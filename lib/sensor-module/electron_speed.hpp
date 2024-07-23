#ifndef _ELECTRON_SPEED_HPP_
#define _ELECTRON_SPEED_HPP_

#include <Arduino.h>

class ElectronSpeed {
    public:
        float speed = 0;
        float last_time = 0;
        int last_sensor_id = 0;

        void get_time(int sensor_id);

        float get_speed();

        ElectronSpeed(float radius);

    private:
        float distance = 0;

};

#endif  // _ELECTRON_SPEED_HPP_