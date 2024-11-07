#include <TemperatureSensor.h>
#ifndef __TEMPERATURE_CONTROLLER__
#define __TEMPERATURE_CONTROLLER__

class TemperatureController {
    public:
        TemperatureController();
        void attachSensor(TemperatureSensor* sensor);
        void detachSensor();
        void readTemp();
        bool isTemperatureHigh();
    private:
        TemperatureSensor* tempSensor;
        int currentTemp;
};

#endif