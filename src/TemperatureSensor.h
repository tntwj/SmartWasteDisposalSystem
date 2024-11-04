#ifndef __TEMPERATURE_SENSOR__
#define __TEMPERATURE_SENSOR__

class TemperatureSensor {
    public:
        TemperatureSensor(int pin);
        int readTemperature();
    private:
        int pin;
};

#endif
