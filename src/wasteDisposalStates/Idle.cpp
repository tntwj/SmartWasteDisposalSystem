#include "Idle.h"
#include "EnteringWaste.h"
#include "SleepState.h"
#include "headers/Defines.h"
#include "tasks/WasteDisposalTask.h"

Idle::Idle() {
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
