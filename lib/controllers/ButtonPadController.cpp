#include "ButtonPadController.h"

#include "EnableInterrupt.h"
#include "Arduino.h"

ButtonPadController* instance;

/**
 * Only one ButtonPadController may exist at any time due to the interrupt constraints.
 */
ButtonPadController::ButtonPadController(int openPin, int closePin) {
    this->openPin = openPin;
    this->closePin = closePin;
    this->openPressed = false;
    this->closePressed = false;
}

void ButtonPadController::init() {
    pinMode(this->openPin, INPUT);
    pinMode(this->closePin, INPUT);
    enableInterrupt(this->openPin, openButtonISR, HIGH);
    enableInterrupt(this->closePin, closeButtonISR, HIGH);
    instance = this;
}

void ButtonPadController::setOpenPressed(bool pressed) {
    this->openPressed = pressed;
}

void ButtonPadController::setClosePressed(bool pressed) {
    this->closePressed = pressed;
}

bool ButtonPadController::isOpenPressed() {
    return this->openPressed;
}

bool ButtonPadController::isClosePressed() {
    return this->closePressed;
}

void ButtonPadController::openButtonISR() {
    if (instance) {
        instance->setOpenPressed(true);
    }
}

void ButtonPadController::closeButtonISR() {
    if (instance) {
        instance->setClosePressed(true);
    }
}
