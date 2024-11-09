#include <Arduino.h>
#include "Pins.h"
#include <ButtonPadController.h>

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e buttons && pio device monitor
 */

ButtonPadController* buttonPadController;

void setup() {
    Serial.begin(9600);
    Serial.println("### This is a ButtonPadController test ###");
    buttonPadController = new ButtonPadController(new ButtonImpl(OPEN_BUTTON_PIN), new ButtonImpl(CLOSE_BUTTON_PIN));
    Serial.println("OPEN pressed?: " + String(buttonPadController->isOpenPressed()));
    Serial.println("CLOSE pressed?: " + String(buttonPadController->isClosePressed()));
    Serial.println("### End of setup ###");
}

void loop() {
    if (buttonPadController->isOpenPressed()) {
        Serial.println("OPEN pressed!");
    }
    if (buttonPadController->isClosePressed()) {
        Serial.println("CLOSE pressed!");
    }
    delay(50);
}