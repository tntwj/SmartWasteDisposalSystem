#include "WasteReceived.h"
#include "headers/Defines.h"
#include "Idle.h"

WasteReceived::WasteReceived() {
}

void WasteReceived::init() {
    stateMsg="WASTE_RECEIVED";
    Serial.println("waste received");
    doorController->close();
    currentTime = millis();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("WASTE RECEIVED");
}

State* WasteReceived::handle() {
    if (millis() - currentTime >= WASTE_RECEIVED_PERIOD) {
        return new Idle();
    }
    return nullptr;
}
