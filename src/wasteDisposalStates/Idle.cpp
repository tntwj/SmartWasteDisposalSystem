#include "Idle.h"
#include "EnteringWaste.h"
#include "SleepState.h"
#include "headers/Defines.h"

Idle::Idle() {
}

void Idle::init() {
    Serial.println("State Idle");
    currentTime = millis();
    ledController->switchOnGreen();
}

State* Idle::handle() {
    bool isOpenPressed = buttonPadController->isOpenPressed();
    if (isOpenPressed) {
        return new EnteringWaste();
    }
    if (motionDetector->hasDetected()) {
        currentTime = millis();
    }
    if (millis() - currentTime >= AWAKE_PERIOD) {
        return new SleepState();
    }
    return nullptr;
}
