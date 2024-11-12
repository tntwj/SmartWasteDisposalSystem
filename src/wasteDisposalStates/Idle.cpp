#include "Idle.h"
#include "EnteringWaste.h"
#include "SleepState.h"
#include "headers/Defines.h"

Idle::Idle() {
}

void Idle::init() {
    ledController->switchOnGreen();
}

State* Idle::handle() {
    if (buttonPadController->isOpenPressed()) {
        return new EnteringWaste();
    }
    count++;
    if (count > limit) {
        count = 0;
        return new SleepState();
    }
    return nullptr;
}
