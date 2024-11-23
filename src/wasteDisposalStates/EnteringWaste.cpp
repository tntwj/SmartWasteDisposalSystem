#include "EnteringWaste.h"
#include "headers/Defines.h"
#include "ContainerFull.h"
#include "WasteReceived.h"
#include <Arduino.h>

void EnteringWaste::execute() {
    stateMessage = "ENTERING_WASTE";
    doorController->openFront();
    lcdController->printEnteringWasteMessage();
    noInterrupts();
    closePressed = false;
    interrupts();
    startTime = millis();
}

State* EnteringWaste::next() {
    if (wasteDetector->isFull()) {
        return new ContainerFull();
    }
    noInterrupts();
    bool currentCloseButtonState = closePressed;
    interrupts();
    if (currentCloseButtonState || millis() - startTime >= ENTERING_WASTE_WINDOW) {
        noInterrupts();
        closePressed = false;
        interrupts();
        return new WasteReceived();
    } else {
        return nullptr;
    }
}