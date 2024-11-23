#include "ContainerFull.h"
#include "SleepState.h"
#include "EmptyingProcess.h"

void ContainerFull::execute() {
    state = "CONTAINER_FULL";
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("CONTAINER FULL");
    startTime = millis();
}

State* ContainerFull::next() {
    if (millis() - startTime >= AWAKE_PERIOD) {
        return new SleepState(CONTAINER_FULL);
    }
    if (state == "EMPTYING_PROCESS") {
        return new EmptyingProcess();
    }
    return nullptr;
}
