#include <Arduino.h>
#include <Pins.h>
#include <Defines.h>
#include <ButtonPadController.h>
#include <DoorController.h>
#include <MotionDetector.h>
#include <TemperatureController.h>
#include <WasteDetector.h>

/**
 * Use the following command in PlatformIO terminal:
 * pio run -t upload -e controllers && pio device monitor
 */

ButtonPadController* buttonPadController;
DoorController* doorController;
MotionDetector* motionDetector;
TemperatureController* temperatureController;
WasteDetector* wasteDetector;


void setup() {
    buttonPadController = new ButtonPadController(OPEN_BUTTON_PIN, CLOSE_BUTTON_PIN);
    Servo* servo = new Servo();
    servo->attach(SERVO_PIN);
    doorController = new DoorController(servo);
    motionDetector = new MotionDetector(new PirSensor(PIR_SENSOR_PIN));
    temperatureController = new TemperatureController(new TemperatureSensor(TEMP_SENSOR_PIN), TEMPERATURE_THRESHOLD);
    wasteDetector = new WasteDetector(new UltraSoundProxy(ULTRA_SOUND_ECHO_PIN, ULTRA_SOUND_TRIG_PIN), MAX_WASTE_LEVEL, MIN_WASTE_LEVEL);
}

void loop() {
    delay(1000);
}