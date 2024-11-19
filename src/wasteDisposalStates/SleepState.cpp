#include "SleepState.h"
#include "Idle.h"
#include "ContainerFull.h"
#include <Arduino.h>
#include "controllers/Interrupts.h"


SleepState::SleepState() {
}

void wakeUp1() {
}

void SleepState::init() {
    ledController->switchOffGreen();
    ledController->switchOffRed();
    lcd->clear();
    lcd->noBacklight();
    lcd->noDisplay();
    sleep();
    // Enable interrupt on pir pin when the tension rises to wake up.
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

