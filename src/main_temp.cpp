#include <Arduino.h>
#include "headers/Pins.h"
#include "headers/Defines.h"
#include "controllers/TemperatureController.h"

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e temp && pio device monitor
 */

TemperatureController* temperatureController;

void setup() {
    Serial.begin(9600);
    Serial.println("### This is a TemperatureController test ###");
    temperatureController = new TemperatureController(new TemperatureSensor(TEMP_SENSOR_PIN), TEMPERATURE_THRESHOLD);
    Serial.println("### End of setup ###");
}

void loop() {
    temperatureController->readTemp();
    Serial.println("Room temperature: " + String(temperatureController->getTemp()));
    Serial.println("Temperature higher than "
        + String(temperatureController->getThreshold())
        + " degrees? "
        + String(temperatureController->isTempHigh()));
    delay(1000);
}