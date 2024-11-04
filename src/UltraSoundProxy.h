#ifndef __ULTRASOUND_PROXY__
#define __ULTRASOUND_PROXY__

class UltraSoundProxy {
    public:
        UltraSoundProxy(int trigPin, int echoPin);
        float getDistance();
    private:
        int trigPin;
        int echoPin;
};

#endif