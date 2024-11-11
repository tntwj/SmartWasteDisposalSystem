#include <Arduino.h>
#include "headers/Pins.h"
#include "controllers/MotionDetector.h"

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e motion && pio device monitor
 */

MotionDetector* motionDetector;

void setup() {
    Serial.begin(9600);
    Serial.println("### This is a MotionDetector test ###");
    motionDetector = new MotionDetector(new PirSensor(PIR_SENSOR_PIN));
    delay(15000);
    Serial.println("### End of setup ###");
}

void loop() {
    motionDetector->sense();
    if (motionDetector->hasDetected()) {
        Serial.println("Detected something!");
    }
    delay(1000);
}