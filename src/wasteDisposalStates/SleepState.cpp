#include "SleepState.h"
#include "Idle.h"
#include "ContainerFull.h"
#include <Arduino.h>
#include "controllers/Interrupts.h"

void SleepState::init() {
    ledController->switchOffGreen();
    ledController->switchOffRed();
    lcd->clear();
    lcd->noBacklight();
    lcd->noDisplay();
    sleep();
}

State* SleepState::handle() {
    if (motionDetector->hasDetected()) {
        lcd->display();
        lcd->backlight();
        if (stateMsg == "IDLE") {
            return new Idle();
        } else if (stateMsg == "CONTAINER_FULL") {
            return new ContainerFull();
        }
    }
    return nullptr;
}
