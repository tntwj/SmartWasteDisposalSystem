#ifndef __SLEEP_STATE__
#define __SLEEP_STATE__

#include "State.h"
#include "controllers/MotionDetector.h"
#include <LiquidCrystal_I2C.h>

extern String stateMsg;
extern MotionDetector* motionDetector;
extern LiquidCrystal_I2C* lcd;

class SleepState: public State {
    public:
        SleepState();
        void init() override;
        State* handle() override;
};

#endif