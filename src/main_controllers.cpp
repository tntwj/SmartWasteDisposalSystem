#include <Arduino.h>
#include "headers/Pins.h"
#include "headers/Defines.h"
#include "controllers/ButtonPadController.h"
#include "controllers/DoorController.h"
#include "controllers/MotionDetector.h"
#include "controllers/TemperatureController.h"
#include "controllers/WasteDetector.h"
#include "controllers/LedController.h"

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e controllers && pio device monitor
 */

ButtonPadController* buttonPadController;
DoorController* doorController;
MotionDetector* motionDetector;
LedController* ledController;
TemperatureController* temperatureController;
WasteDetector* wasteDetector;


void setup() {
    buttonPadController = new ButtonPadController(OPEN_BUTTON_PIN, CLOSE_BUTTON_PIN);
    Servo* servo = new Servo();
    servo->attach(SERVO_PIN);
    doorController = new DoorController(servo);
    motionDetector = new MotionDetector(new PirSensor(PIR_SENSOR_PIN));
    ledController = new LedController(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));
    temperatureController = new TemperatureController(new TemperatureSensor(TEMP_SENSOR_PIN), TEMPERATURE_THRESHOLD);
    wasteDetector = new WasteDetector(new UltraSoundProxy(ULTRA_SOUND_ECHO_PIN, ULTRA_SOUND_TRIG_PIN), MAX_WASTE_LEVEL, MIN_WASTE_LEVEL);
}

void loop() {
    delay(1000);
}