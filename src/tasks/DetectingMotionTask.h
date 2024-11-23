#ifndef __DETECTING_MOTION__
#define __DETECTING_MOTION__

#include "Task.h"
#include "controllers/MotionDetector.h"

extern MotionDetector* motionDetector;

class DetectingMotionTask: public Task {
    public:
        void tick() override;
};

#endif
