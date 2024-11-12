#include "ButtonPadController.h"

#include <Arduino.h>
#include <EnableInterrupt.h>

void setupButtons(int openPin, int closePin) {
    pinMode(openPin, INPUT);
    pinMode(closePin, INPUT);
    enableInterrupt(openPin, openButtonISR, HIGH);
    enableInterrupt(closePin, closeButtonISR, HIGH);
}

void openButtonISR() {
    openPressed = true;
}

void closeButtonISR() {
    closePressed = true;
}
