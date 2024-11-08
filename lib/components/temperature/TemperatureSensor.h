#ifndef __TEMPERATURE_SENSOR__
#define __TEMPERATURE_SENSOR__

class TemperatureSensor {
    public:
        TemperatureSensor(int pin);
        int getTemp();
    private:
        int pin;
};

#endif
