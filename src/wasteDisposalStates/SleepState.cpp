#include "SleepState.h"
#include "Idle.h"
#include "ContainerFull.h"

SleepState::SleepState() {
    //sleep
}

void SleepState::init() {

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