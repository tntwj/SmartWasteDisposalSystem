#ifndef __IDLE__
#define __IDLE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"
#include "controllers/MotionDetector.h"


extern LedController* ledController;
extern MotionDetector* motionDetector;

class Idle : public State {
    private:
    unsigned long currentTime;
    public:
        Idle();
        void init() override;
        State* handle() override;
};

#endif
