#include <Arduino.h>
#include "Pins.h"
#include <ButtonPadController.h>
#include "LedController.h" // To be removed

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e buttons && pio device monitor
 */

ButtonPadController* buttonPadController = new ButtonPadController(OPEN_BUTTON_PIN, CLOSE_BUTTON_PIN);

void setup() {
    Serial.begin(9600);
    Serial.println("### This is a ButtonPadController test ###");
    buttonPadController->init();
    Serial.println("### End of setup ###");
}

void loop() {
    if (buttonPadController->isOpenPressed()) {
        Serial.println("OPEN pressed!");
    }
    if (buttonPadController->isClosePressed()) {
        Serial.println("CLOSE pressed!");
    }
    delay(1000);
}