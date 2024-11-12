#include "EnteringWaste.h"
#include "headers/Defines.h"
#include "ContainerFull.h"
#include "WasteReceived.h"
#include <Arduino.h>

EnteringWaste::EnteringWaste() {
    Serial.print("Entering Waste");
}

void EnteringWaste::init() {
    doorController->openFront();
}

State* EnteringWaste::handle() {
    count++;
    if (wasteDetector->getLevel() >= MAX_WASTE_LEVEL) {
        count = 0;
        return new ContainerFull();
    }
    if (buttonPadController->isClosePressed() || count >= limit) {
        count = 0;
        return new WasteReceived();
    }
    return nullptr;
}