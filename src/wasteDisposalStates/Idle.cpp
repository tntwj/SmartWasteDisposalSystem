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
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("PRESS OPEN TO");
    lcd->setCursor(1, 0);
    lcd->print("ENTER WASTE");
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
