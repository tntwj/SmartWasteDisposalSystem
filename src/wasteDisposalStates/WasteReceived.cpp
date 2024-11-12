#include "WasteReceived.h"
#include "headers/Defines.h"
#include "Idle.h"

WasteReceived::WasteReceived() {
}

void WasteReceived::init() {
    stateMsg="WASTERECEIVED";
    Serial.println("waste received");
    doorController->close();
}

State* WasteReceived::handle() {
    if (millis() - currentTime >= WASTE_RECEIVED_PERIOD) {
        return new Idle();
    }
    return nullptr;
}
