#include "SleepState.h"
#include <WasteDisposalTask.h>
#include "Idle.h"
#include "ContainerFull.h"

class SleepState: public State {
    SleepState() {
        //sleep
    }
    State* handle() override {
        if (motionDetector->hasDetected() && ledController->isGreenOn()) {
            return new Idle();
        }
        if (motionDetector->hasDetected() && ledController->isRedOn()) {
            return new ContainerFull();
        }
        return nullptr;
    }
};