#include "EnteringWaste.h"
#include "headers/Defines.h"
#include "ContainerFull.h"
#include "WasteReceived.h"
#include <Arduino.h>

void EnteringWaste::execute() {
    state = "ENTERING_WASTE";
    doorController->openFront();
    ledController->switchOnGreen();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("PRESS CLOSE");
    lcd->setCursor(0, 1);
    lcd->print("WHEN DONE");
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
    if (currentCloseButtonState || millis() - startTime >= ENTERING_WASTE_PERIOD) {
        noInterrupts();
        closePressed = false;
        interrupts();
        return new WasteReceived();
    }
    return nullptr;
}