#include "ContainerFull.h"
#include "SleepState.h"
#include "EmptyingProcess.h"

ContainerFull::ContainerFull() {
}

void ContainerFull::init() {
    stateMsg = "CONTAINER_FULL";
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
    currentTime = millis();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("CONTAINER FULL");
}

State* ContainerFull::handle() {
    if (millis() - currentTime >= AWAKE_PERIOD) {
        return new SleepState();
    }
    if (stateMsg == "EMPTYING_PROCESS") {
        return new EmptyingProcess();
    }
    return nullptr;
}
