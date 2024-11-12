#include "ContainerFull.h"
#include "SleepState.h"

ContainerFull::ContainerFull() {
}

void ContainerFull::init() {
    stateMsg="CONTAINERFULL";
    Serial.println("container full");
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
}

State* ContainerFull::handle() {
    if (millis() - currentTime >= AWAKE_PERIOD) {
        return new SleepState();
    }
    return nullptr;
}