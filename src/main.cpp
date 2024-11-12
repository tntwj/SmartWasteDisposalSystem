#include <Arduino.h>
#include "controllers/ButtonPadController.h"
#include "controllers/MotionDetector.h"
#include "controllers/TemperatureController.h"
#include "controllers/DoorController.h"
#include "controllers/WasteDetector.h"
#include "controllers/LedController.h"
#include "headers/Pins.h"
#include "headers/Defines.h"
#include "scheduler/Scheduler.h"
#include "tasks/MeasureLevelTask.h"
#include "tasks/MeasureTemperatureTask.h"
#include "tasks/WasteDisposalTask.h"
#include "LiquidCrystal_I2C.h"
#include "communication/MsgService.h"

ButtonPadController* buttonPadController;
DoorController* doorController;
MotionDetector* motionDetector;
TemperatureController* tempController;
WasteDetector* wasteDetector;
LedController* ledController;
LiquidCrystal_I2C* lcd = new LiquidCrystal_I2C(0x27, 16, 2);
Scheduler sched;

void setup() {
    MsgService.init();
    buttonPadController = new ButtonPadController(OPEN_BUTTON_PIN, CLOSE_BUTTON_PIN);
    PWMServo* servo = new PWMServo();
    servo->attach(SERVO_PIN);
    doorController = new DoorController(servo);
    motionDetector = new MotionDetector(new PirSensor(PIR_SENSOR_PIN));
    tempController = new TemperatureController(new TemperatureSensor(TEMP_SENSOR_PIN), TEMPERATURE_THRESHOLD);
    wasteDetector = new WasteDetector(new UltraSoundProxy(ULTRA_SOUND_ECHO_PIN, ULTRA_SOUND_TRIG_PIN), MAX_WASTE_LEVEL, MIN_WASTE_LEVEL);
    ledController = new LedController(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));
	lcd->init();
	lcd->backlight();

    sched.init(50);

    /*creating tasks and add to scheduler*/
    Task* measureLevel = new MeasureLevelTask();
    measureLevel->init(MEASURE_LEVEL_PERIOD);
    sched.addTask(measureLevel);
    Task* measureTemp = new MeasureTemperatureTask();
    measureTemp->init(MEASURE_TEMPERATURE_PERIOD);
    sched.addTask(measureTemp);
    Task* wasteDisposalTask = new WasteDisposalTask();
    wasteDisposalTask->init(WASTE_DISPOSAL_TASK_PERIOD);
    sched.addTask(wasteDisposalTask);
}

void loop() {
  sched.schedule();
}
