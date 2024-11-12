#include "Idle.h"
#include "EnteringWaste.h"
#include "SleepState.h"
#include "headers/Defines.h"

Idle::Idle() {
}

void Idle::init() {
    stateMsg = "IDLE";
    Serial.println("State Idle");
    currentTime = millis();
    ledController->switchOnGreen();
}

State* Idle::handle() {
    Serial.println("is pressed " + String(openPressed));
    if (openPressed) {
        openPressed = false;
        return new EnteringWaste();
    }
    Serial.println("Movemente detected " + String(movementDetected));
    if (movementDetected) {
        currentTime = millis();
    }
    if (millis() - currentTime >= AWAKE_PERIOD) {
        return new SleepState();
    }
    return nullptr;
}
