#include "Idle.h"
#include "EnteringWaste.h"
#include "SleepState.h"
#include "headers/Defines.h"
#include <Arduino.h>

Idle::Idle() {
}

void Idle::init() {
    Serial.print("State Idle");
    ledController->switchOnGreen();
}

State* Idle::handle() {
    bool isOpenPressed = openPressed;
    Serial.println("is pressed" + String(openPressed));
    Serial.println("is close pressed" + String(closePressed));
    if (isOpenPressed) {
        return new EnteringWaste();
    }
    count++;
    Serial.println(count);
    if (count > limit) {
        count = 0;
        return new SleepState();
    }
    return nullptr;
}
