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

    // Enable interrupt on pir pin when the tension rises to wake up.
    // Needs a pir state machine
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