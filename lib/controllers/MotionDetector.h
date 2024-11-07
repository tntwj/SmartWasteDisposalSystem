#ifndef __MOTION_DETECTOR__
#define __MOTION_DETECTOR__

#include "PirSensor.h"

class MotionDetector {
    public:
        MotionDetector();
        void attachSensor(PirSensor* sensor);
        void detachSensor();
        void detect();
        bool hasDetected();
    private:
        PirSensor* sensor;
        bool detected;
};

#endif
