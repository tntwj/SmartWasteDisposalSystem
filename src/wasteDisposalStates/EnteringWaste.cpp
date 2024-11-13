#include "EnteringWaste.h"
#include "headers/Defines.h"
#include "ContainerFull.h"
#include "WasteReceived.h"
#include <Arduino.h>

EnteringWaste::EnteringWaste() {
    Serial.println("Entering Waste");
}

void EnteringWaste::init() {
    stateMsg="ENTERING_WASTE";
    currentTime = millis();
    doorController->openFront();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("PRESS CLOSE");
    lcd->setCursor(0, 1);
    lcd->print("WHEN DONE");
    closePressed = false;
}

State* EnteringWaste::handle() {
    Serial.println("Waste level: " + String(wasteDetector->getLevel()));
    Serial.println("Measured distance " + String(wasteDetector->getDistance()));
    if (wasteDetector->isFull()) {
        return new ContainerFull();
    }
    if (closePressed || millis() - currentTime >= ENTERING_WASTE_PERIOD) {
        closePressed = false;
        return new WasteReceived();
    }
    return nullptr;
}