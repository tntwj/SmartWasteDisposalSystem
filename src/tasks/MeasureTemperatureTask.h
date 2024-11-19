#ifndef __MEASURE_TEMPERATURE_TASK__
#define __MEASURE_TEMPERATURE_TASK__

#include "Task.h"
#include "controllers/TemperatureController.h"

extern TemperatureController* tempController;

class MeasureTemperatureTask: public Task {
    public:
        void tick();
};

#endif
