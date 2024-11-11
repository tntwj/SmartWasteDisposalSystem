#include <Arduino.h>
#include "controllers/ButtonPadController.h"
#include "controllers/MotionDetector.h"
#include "controllers/TemperatureController.h"
#include "controllers/DoorController.h"
#include "controllers/WasteDetector.h"
#include "headers/Pins.h"
#include "headers/Defines.h"
#include "scheduler/Scheduler.h"
#include "tasks/MeasureLevelTask.h"
#include "tasks/MeasureTemperatureTask.h"
#include "tasks/WasteDisposalTask.h"

ButtonPadController* buttonPadController;
DoorController* doorController;
MotionDetector* motionDetector;
TemperatureController* temperatureController;
WasteDetector* wasteDetector;
Scheduler sched;

void setup() {
    buttonPadController = new ButtonPadController(OPEN_BUTTON_PIN, CLOSE_BUTTON_PIN);
    Servo* servo = new Servo();
    servo->attach(SERVO_PIN);
    doorController = new DoorController(servo);
    motionDetector = new MotionDetector(new PirSensor(PIR_SENSOR_PIN));
    temperatureController = new TemperatureController(new TemperatureSensor(TEMP_SENSOR_PIN), TEMPERATURE_THRESHOLD);
    wasteDetector = new WasteDetector(new UltraSoundProxy(ULTRA_SOUND_ECHO_PIN, ULTRA_SOUND_TRIG_PIN), MAX_WASTE_LEVEL, MIN_WASTE_LEVEL);

    /**
     * Reminder that Serial.Begin() is later called in MsgService
     */
    Serial.begin(9600);
    Serial.println("ArduinoUno");
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
