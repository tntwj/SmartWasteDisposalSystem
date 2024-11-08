#ifndef __PIR_SENSOR__
#define __PIR_SENSOR__

class PirSensor {
    public:
        PirSensor(int pin);
        bool hasDetected();
    private:
        int pin;
};

#endif