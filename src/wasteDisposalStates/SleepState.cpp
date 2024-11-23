#include "SleepState.h"
#include "Idle.h"
#include "ContainerFull.h"
#include <Arduino.h>
#include "controllers/Interrupts.h"

void SleepState::execute() {
    ledController->isGreenOn() ? ledController->switchOffRed() : ledController->switchOffGreen();
    lcdController->turnOff();
    sleep();
    lcdController->turnOn();
}

SleepState::SleepState(PreviousState prevState) {
    this->prevState = prevState;
}

State* SleepState::next() {
    if (prevState == IDLE) {
        return new Idle();
    } else if (prevState == CONTAINER_FULL) {
        return new ContainerFull();
    } else {
        return nullptr;
    }
}
