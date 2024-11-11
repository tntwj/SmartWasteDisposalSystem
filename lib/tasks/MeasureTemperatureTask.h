#ifndef __MEASURETEMPERATURETASK__
#define __MEASURETEMPERATURETASK__
#include "Task.h"
#include "TemperatureController.h"
#include "Pins.h"
#include "Defines.h"

extern TemperatureController* tempController;

class MeasureTemperatureTask: public Task {

    public:
        void tick();
};

#endif