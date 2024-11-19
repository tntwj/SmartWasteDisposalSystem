#include "Interrupts.h"

#include <Arduino.h>
#include <EnableInterrupt.h>
#include "headers/Pins.h"
#include <avr/sleep.h>

/**
 * Since having we estimated an unacceptable worst case execution time when all tasks are combined together
 * we decided to handle the buttons readings via interrupts.
 * However, using this approach implies that whoever reads the state of the presses must handle these with great care.
 */
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

/**
 * Puts the system to sleep and wakes up upon sensing a rising signal through the PIR pin.
 */
void sleep() {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    enableInterrupt(PIR_PIN, wake, RISING);
    sleep_mode();
    sleep_disable();
    disableInterrupt(PIR_PIN);
}

/**
 * Dummy function used by the as an interrupt function.
 */
void wake() {
}
