#include "SleepState.h"
#include "tasks/WasteDisposalTask.h"
#include "Idle.h"
#include "ContainerFull.h"

SleepState::SleepState() {
    //sleep
}
State* SleepState::handle() {
    if (motionDetector->hasDetected() && ledController->isGreenOn()) {
        return new Idle();
    }
    if (motionDetector->hasDetected() && ledController->isRedOn()) {
        return new ContainerFull();
    }
    return nullptr;
}