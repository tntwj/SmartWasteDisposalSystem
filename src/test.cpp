#include <Arduino.h>
#include "Wire.h"
#include "LedController.h"
#include "Pins.h"

LedController* ledController;

void setup() {
    Serial.begin(9600);
    Serial.println("This is a LedController test");
    ledController = new LedController();
    ledController->attachGreenLed(new Led(GREEN_LED_PIN));
    ledController->attachRedLed(new Led(RED_LED_PIN));
    Serial.println("Green Led on?: " + String(ledController->isGreenOn()));
    Serial.println("Red Led on?: " + String(ledController->isRedOn()));
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