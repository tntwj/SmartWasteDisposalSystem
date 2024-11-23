#include "WasteReceived.h"
#include "headers/Defines.h"
#include "Idle.h"

void WasteReceived::execute() {
    state = "WASTE_RECEIVED";
    doorController->close();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("WASTE RECEIVED");
    startTime = millis();
}

State* WasteReceived::next() {
    if (millis() - startTime >= WASTE_RECEIVED_PERIOD) {
        return new Idle();
    }
    return nullptr;
}
