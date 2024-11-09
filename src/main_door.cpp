#include <Arduino.h>
#include "Pins.h"
#include "Defines.h"
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
    Serial.println("### End of setup ###");
}

void loop() {
    delay(1000);
}