#include "EmptyingProcess.h"
#include "headers/Defines.h"
#include "Idle.h"

EmptyingProcess::EmptyingProcess() {
}

void EmptyingProcess::init() {
    doorController->openBack();
}

State* EmptyingProcess::handle() {
    if (millis() - currentTime >= EMPTYING_PROCESS) {
        doorController->close();
        ledController->switchOffRed();
        return new Idle();
    }
    return nullptr;
}
