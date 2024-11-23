#include "ContainerFull.h"
#include "SleepState.h"
#include "EmptyingProcess.h"

void ContainerFull::init() {
    stateMsg = "CONTAINER_FULL";
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("CONTAINER FULL");
    startTime = millis();
}

State* ContainerFull::handle() {
    if (millis() - startTime >= AWAKE_PERIOD) {
        return new SleepState();
    }
    if (stateMsg == "EMPTYING_PROCESS") {
        return new EmptyingProcess();
    }
    return nullptr;
}
