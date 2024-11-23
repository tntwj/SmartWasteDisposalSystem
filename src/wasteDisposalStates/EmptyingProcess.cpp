#include "EmptyingProcess.h"
#include "headers/Defines.h"
#include "Idle.h"

void EmptyingProcess::execute() {
    state = "EMPTYING_PROCESS";
    doorController->openBack();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("EMPTYING");
    lcd->setCursor(0, 1);
    lcd->print("PROCESS");
    this->startTime = millis();
}

State* EmptyingProcess::next() {
    if (millis() - startTime >= EMPTYING_PROCESS) {
        doorController->close();
        ledController->switchOffRed();
        return new Idle();
    }
    return nullptr;
}
