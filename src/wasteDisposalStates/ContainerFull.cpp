#include "ContainerFull.h"
#include "SleepState.h"
#include "EmptyingProcess.h"

ContainerFull::ContainerFull() {
}

void ContainerFull::init() {
    stateMsg="CONTAINERFULL";
    Serial.println("container full");
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
    if (stateMsg == "EMPTYINGPROCESS") {
        return new EmptyingProcess();
    }
    return nullptr;
}