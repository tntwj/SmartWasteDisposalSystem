#ifndef __DETECTINGMOTION__
#define __DETECTINGMOTION__
#include "Task.h"
#include "controllers/MotionDetector.h"

extern MotionDetector* motionDetector;

class DetectingMotionTask: public Task {
    public:
        void tick();
};

#endif