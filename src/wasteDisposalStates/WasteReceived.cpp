#include "WasteReceived.h"
#include "headers/Defines.h"
#include "Idle.h"

void WasteReceived::execute() {
    stateMessage = "WASTE_RECEIVED";
    doorController->close();
    lcdController->printWasteReceivedMessage();
    startTime = millis();
}

State* WasteReceived::next() {
    if (millis() - startTime >= WASTE_RECEPTION_WINDOW) {
        return new Idle();
    } else {
        return nullptr;
    }
}
