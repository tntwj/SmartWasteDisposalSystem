#include "ContainerFull.h"
#include "SleepState.h"
#include "EmptyingProcess.h"

void ContainerFull::execute() {
    stateMessage = "CONTAINER_FULL";
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
    lcdController->printContainerFullMessage();
    isContainerBeingEmptied = false;
    startTime = millis();
}

State* ContainerFull::next() {
    if (millis() - startTime >= SLEEP_TIMEOUT_WINDOW) {
        return new SleepState(CONTAINER_FULL);
    } else if (isContainerBeingEmptied) {
        return new EmptyingProcess();
    } else {
        return nullptr;
    }
}
