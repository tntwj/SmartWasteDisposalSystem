#include <Arduino.h>
#include "Pins.h"
#include <LedController.h>
#include <MotionDetector.h>
#include <DoorController.h>

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e door && pio device monitor
 */

DoorController* doorController;

void setup() {
    Serial.begin(9600);
    Serial.println("### This is a DoorController test ###");
    Servo* servo = new Servo();
    servo->attach(SERVO_PIN);
    doorController = new DoorController(servo);
    delay(1000);
    Serial.println("### End of setup ###");
}

void loop() {
    doorController->openFront();
    Serial.println("Opening front");
    doorController->close();
    Serial.println("Closing");
    doorController->openBack();
    Serial.println("Opening back");
    doorController->close();
    Serial.println("Closing");
}