#ifndef __MEASURETEMPERATURETASK__
#define __MEASURETEMPERATURETASK__
#include "Task.h"
#include "TemperatureController.h"

class MeasureTemperatureTask: public Task {
    private:
        TemperatureController tempController;
    public:
        void tick() {
        }
};

#endif