#include "EnteringWaste.h"
#include "headers/Defines.h"
#include "ContainerFull.h"
#include "WasteReceived.h"
#include <Arduino.h>

EnteringWaste::EnteringWaste() {
    Serial.println("Entering Waste");
}

void EnteringWaste::init() {
    doorController->openFront();
}

State* EnteringWaste::handle() {
    if (wasteDetector->getLevel() >= MAX_WASTE_LEVEL) {
        return new ContainerFull();
    }
    if (millis() - currentTime >= ENTERING_WASTE_PERIOD) {
        return new WasteReceived();
    }
    return nullptr;
}