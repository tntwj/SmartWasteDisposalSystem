#include "SleepState.h"
#include "Idle.h"
#include "ContainerFull.h"
#include <Arduino.h>

SleepState::SleepState() {
    //sleep
    stateMsg="SLEEP";
    Serial.println("Sleep");
}

void SleepState::init() {
    ledController->switchOffGreen();
    ledController->switchOffRed();
    lcd->clear();
    lcd->noBacklight();
    lcd->noDisplay();
}

State* SleepState::handle() {
    if (movementDetected && ledController->isGreenOn()) {
        return new Idle();
    }
    if (movementDetected && ledController->isRedOn()) {
        return new ContainerFull();
    }
    return nullptr;
}