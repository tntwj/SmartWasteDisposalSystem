#include "SleepState.h"
#include "Idle.h"

class SleepState: public State {
    SleepState() {
        //sleep
    }
    State* handle() override {
        if (motionDetector->hasDetected()) {
            return new Idle();
        }
        return nullptr;
    }
};