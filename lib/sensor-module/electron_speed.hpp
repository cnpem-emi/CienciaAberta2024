#ifndef _ELECTRON_SPEED_HPP_
#define _ELECTRON_SPEED_HPP_

#include <Arduino.h>

class ElectronSpeed {
    public:
        float speed;

        void get_time(int sensor_id);

        float get_speed();

        ElectronSpeed(float radius);

    private:
        float last_time = 0;
        int last_sensor_id = 0;
        float distance = 0;

};

#endif  // _ELECTRON_SPEED_HPP_