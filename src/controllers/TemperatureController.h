#ifndef __TEMPERATURE_CONTROLLER__
#define __TEMPERATURE_CONTROLLER__

#include "components/TemperatureSensor.h"

class TemperatureController {
    public:
        TemperatureController(TemperatureSensor* sensor, int tempThreshold);
        ~TemperatureController();
        void readTemp();
        int getTemp();
        int getThreshold();
        bool isTempHigh();
    private:
        TemperatureSensor* tempSensor;
        int currentTemp;
        int tempThreshold;
};

#endif
