#include "SleepState.h"
#include "Idle.h"
#include "ContainerFull.h"
#include <Arduino.h>
#include "controllers/Interrupts.h"

void SleepState::execute() {
    ledController->switchOffGreen();
    ledController->switchOffRed();
    lcd->clear();
    lcd->noBacklight();
    lcd->noDisplay();
    sleep();
    lcd->display();
    lcd->backlight();
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
