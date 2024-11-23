#ifndef __SLEEP_STATE__
#define __SLEEP_STATE__

#include "State.h"
#include "controllers/MotionDetector.h"
#include <LiquidCrystal_I2C.h>

extern String state;
extern MotionDetector* motionDetector;
extern LiquidCrystal_I2C* lcd;

enum PreviousState {IDLE, CONTAINER_FULL};

class SleepState: public State {
    private:
        PreviousState prevState;
    public:
        SleepState(PreviousState);
        void execute() override;
        State* next() override;
};

#endif
