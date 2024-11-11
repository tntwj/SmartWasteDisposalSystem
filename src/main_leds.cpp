#include <Arduino.h>
#include "controllers/LedController.h"
#include "headers/Pins.h"

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e leds && pio device monitor
 */

LedController* ledController;

void setup() {
    Serial.begin(9600);
    Serial.println("### This is a LedController test ###");
    ledController = new LedController(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));
    Serial.println("Green Led on?: " + String(ledController->isGreenOn()));
    Serial.println("Red Led on?: " + String(ledController->isRedOn()));
    Serial.println("### End of setup ###");
}

void loop() {
    Serial.println("Turning on green");
    ledController->switchOnGreen();
    Serial.println("Turning on red");
    ledController->switchOnRed();

    Serial.println("Green Led on?: " + String(ledController->isGreenOn()));
    Serial.println("Red Led on?: " + String(ledController->isRedOn()));

    delay(5000);

    Serial.println("Turning off green");
    ledController->switchOffGreen();
    Serial.println("Turning off red");
    ledController->switchOffRed();

    Serial.println("Green Led on?: " + String(ledController->isGreenOn()));
    Serial.println("Red Led on?: " + String(ledController->isRedOn()));
    delay(5000);
}