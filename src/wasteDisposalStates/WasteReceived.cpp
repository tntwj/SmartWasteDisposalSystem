#include "WasteReceived.h"
#include "headers/Defines.h"
#include "Idle.h"

WasteReceived::WasteReceived() {
}

void WasteReceived::init() {
    doorController->close();
}

State* WasteReceived::handle() {
    if (millis() - currentTime >= WASTE_RECEIVED_PERIOD) {
        return new Idle();
    }
    return nullptr;
}
