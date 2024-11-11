#include <Arduino.h>
#include "headers/Pins.h"
#include "headers/Defines.h"
#include "controllers/WasteDetector.h"

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e waste && pio device monitor
 */

WasteDetector* wasteDetector;

void setup() {
    Serial.begin(9600);
    Serial.println("### This is a WasteDetector test ###");
    wasteDetector = new WasteDetector(new UltraSoundProxy(ULTRA_SOUND_TRIG_PIN,
        ULTRA_SOUND_ECHO_PIN),
        MAX_WASTE_LEVEL,
        MIN_WASTE_LEVEL);
    Serial.println("### End of setup ###");
}

void loop() {
    wasteDetector->readLevel();
    Serial.println("Measured distance: " + String(wasteDetector->getDistance()));
    Serial.println("Measured level: " + String(wasteDetector->getLevel()));
    Serial.println("Full? " + String(wasteDetector->isFull()));
    delay(2000);
}