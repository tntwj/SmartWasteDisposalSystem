#ifndef __MOTION_DETECTOR__
#define __MOTION_DETECTOR__

#include "components/PirSensor.h"

class MotionDetector {
    public:
        MotionDetector(PirSensor* sensor);
        ~MotionDetector();
        void sense();
        bool hasDetected();
    private:
        PirSensor* pirSensor;
        bool detected;
};

#endif
