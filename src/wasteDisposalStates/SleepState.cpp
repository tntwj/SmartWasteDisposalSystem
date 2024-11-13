#include "SleepState.h"
#include "Idle.h"
#include "ContainerFull.h"
#include <Arduino.h>
#include "controllers/Interrupts.h"


SleepState::SleepState() {
    //sleep
    Serial.println("Sleep");
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
    // Needs a pir state machine
}

State* SleepState::handle() {
 
    if (motionDetector->hasDetected() && stateMsg == "IDLE") {
        return new Idle();
    }
    if (motionDetector->hasDetected() && stateMsg == "CONTAINERFULL") {
        return new ContainerFull();
    }
    return nullptr;
}

