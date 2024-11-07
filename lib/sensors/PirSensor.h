#ifndef __PIR_SENSOR__
#define __PIR_SENSOR__

class PirSensor {
    public:
        PirSensor(int pin);
        bool detect();
    private:
        int pin;
};

#endif