#ifndef __MEASURETEMPERATURETASK__
#define __MEASURETEMPERATURETASK__

#include <Task.h>
#include <TemperatureController.h>

extern TemperatureController* tempController;

class MeasureTemperatureTask: public Task {
    public:
        void tick();
};

#endif