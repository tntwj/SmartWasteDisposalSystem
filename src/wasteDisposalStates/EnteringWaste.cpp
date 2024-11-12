#include "EnteringWaste.h"
#include "headers/Defines.h"
#include "ContainerFull.h"
#include "WasteReceived.h"
#include <Arduino.h>

EnteringWaste::EnteringWaste() {
    Serial.println("Entering Waste");
}

void EnteringWaste::init() {
    stateMsg="ENTERINGWASTE";
    doorController->openFront();
}

State* EnteringWaste::handle() {
    Serial.println(wasteDetector->getDistance());
    if (wasteDetector->getLevel() <= MIN_WASTE_LEVEL) {
        return new ContainerFull();
    }
    if (openPressed || millis() - currentTime >= ENTERING_WASTE_PERIOD) {
        return new WasteReceived();
    }
    return nullptr;
}