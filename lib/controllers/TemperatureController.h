#ifndef __TEMPERATURE_CONTROLLER__
#define __TEMPERATURE_CONTROLLER__

#include <TemperatureSensor.h>

class TemperatureController {
    public:
        TemperatureController(TemperatureSensor* sensor);
        ~TemperatureController();
        void readTemp();
        int getTemp();
        bool isTempHigh();
    private:
        TemperatureSensor* tempSensor;
        int currentTemp;
};

#endif
