#include "Interrupts.h"

#include <Arduino.h>
#include <EnableInterrupt.h>
#include "headers/Pins.h"

static int pirPin = 0;

void setupButtons(int openPin, int closePin) {
    pinMode(openPin, INPUT);
    pinMode(closePin, INPUT);
    enableInterrupt(openPin, openButtonISR, RISING);
    enableInterrupt(closePin, closeButtonISR, RISING);
}

void openButtonISR() {
    openPressed = true;
}

void closeButtonISR() {
    closePressed = true;
}

void setupMotionSensor(int pin) {
    pirPin = pin;
    pinMode(pin, INPUT);
    enableInterrupt(pin, pirISR, HIGH);
}

void pirISR() {
    movementDetected = true;
}

