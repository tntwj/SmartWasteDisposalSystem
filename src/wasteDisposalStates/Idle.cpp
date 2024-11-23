#include "Idle.h"
#include "EnteringWaste.h"
#include "SleepState.h"
#include "headers/Defines.h"

void Idle::execute() {
    state = "IDLE";
    ledController->switchOnGreen();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("PRESS OPEN TO");
    lcd->setCursor(0, 1);
    lcd->print("ENTER THE WASTE");
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
    if (millis() - startTime >= AWAKE_PERIOD) {
        return new SleepState(IDLE);
    }
    return nullptr;
}
