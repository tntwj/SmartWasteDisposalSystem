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
    bool isOpenPressed = openPressed;
    Serial.println("is pressed" + String(openPressed));
    if (isOpenPressed) {
        isOpenPressed = false;
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
