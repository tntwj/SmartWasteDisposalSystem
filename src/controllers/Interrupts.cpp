#include "Interrupts.h"

#include <Arduino.h>
#include <EnableInterrupt.h>
#include "headers/Pins.h"
#include <avr/sleep.h>

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

void sleep() {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    enableInterrupt(PIR_PIN, wake, RISING);
    sleep_mode();
    sleep_disable();
    disableInterrupt(PIR_PIN);
}

void wake() {
}