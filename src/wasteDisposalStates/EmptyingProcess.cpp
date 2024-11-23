#include "EmptyingProcess.h"
#include "headers/Defines.h"
#include "Idle.h"

void EmptyingProcess::execute() {
    stateMessage = "EMPTYING_PROCESS";
    doorController->openBack();
    lcdController->printEmptyingMessage();
    this->startTime = millis();
}

State* EmptyingProcess::next() {
    if (millis() - startTime >= EMPTYING_PROCESS_WINDOW) {
        doorController->close();
        ledController->switchOffRed();
        return new Idle();
    } else {
        return nullptr;
    }
}
