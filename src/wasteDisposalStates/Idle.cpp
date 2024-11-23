#include "Idle.h"
#include "EnteringWaste.h"
#include "SleepState.h"
#include "headers/Defines.h"

void Idle::execute() {
    stateMessage = "IDLE";
    ledController->switchOnGreen();
    lcdController->printIdleMessage();
    noInterrupts();
    openPressed = false;
    interrupts();
    startTime = millis();
}

State* Idle::next() {
    noInterrupts();
    bool currentOpenButtonState = openPressed;
    interrupts();
    if (currentOpenButtonState) {
        noInterrupts();
        openPressed = false;
        interrupts();
        return new EnteringWaste();
    }
    if (motionDetector->hasDetected()) {
        startTime = millis();
    }
    if (millis() - startTime >= SLEEP_TIMEOUT_WINDOW) {
        return new SleepState(IDLE);
    } else {
        return nullptr;
    }
}
