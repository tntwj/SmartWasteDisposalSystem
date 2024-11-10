#ifndef __MEASURETEMPERATURETASK__
#define __MEASURETEMPERATURETASK__
#include "Task.h"
#include "TemperatureController.h"
#include "Pins.h"
#include "Defines.h"
TemperatureController* tempController = new TemperatureController(new TemperatureSensor(TEMP_SENSOR_PIN), TEMPERATURE_THRESHOLD);
class MeasureTemperatureTask: public Task {

    public:
        void tick();
};

#endif