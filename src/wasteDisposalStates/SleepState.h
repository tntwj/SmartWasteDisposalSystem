#ifndef __SLEEP_STATE__
#define __SLEEP_STATE__

#include "State.h"
#include "controllers/MotionDetector.h"

extern String stateMsg;
extern bool movementDetected;
class SleepState: public State {
    public:
        SleepState();
        void init() override;
        State* handle() override;
};

#endif