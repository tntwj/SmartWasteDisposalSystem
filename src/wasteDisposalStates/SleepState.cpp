#include "SleepState.h"
#include "Idle.h"
#include "ContainerFull.h"
#include <Arduino.h>

SleepState::SleepState() {
    //sleep
    Serial.println("Sleep");
}

void SleepState::init() {
    ledController->switchOffGreen();
    ledController->switchOffRed();
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