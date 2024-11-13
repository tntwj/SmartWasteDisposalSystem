#include <Arduino.h>
#include "controllers/Interrupts.h"
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
#include "tasks/DetectingMotionTask.h"
#include "LiquidCrystal_I2C.h"
#include "communication/MsgService.h"
#include "tasks/ReceiveMsgTask.h"
#include "tasks/SendMsgTask.h"


DoorController* doorController;
MotionDetector* motionDetector;
TemperatureController* tempController;
WasteDetector* wasteDetector;
LedController* ledController;
LiquidCrystal_I2C* lcd;
Scheduler sched;


bool openPressed = false;
bool closePressed = false;
bool restorePressed = false;
String stateMsg;


void setup() {
    MsgService.init();
	setupButtons(OPEN_PIN, CLOSE_PIN);
    ServoTimer2* servo = new ServoTimer2();
    servo->attach(SERVO_PIN);
    doorController = new DoorController(servo);
    motionDetector = new MotionDetector(new PirSensor(PIR_PIN));
    tempController = new TemperatureController(new TemperatureSensor(TEMP_PIN), TEMP_THRESHOLD);
    wasteDetector = new WasteDetector(new UltraSoundProxy(TRIG_PIN, ECHO_PIN), MAX_WASTE_DISTANCE, MIN_WASTE_DISTANCE);
    ledController = new LedController(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));

	lcd = new LiquidCrystal_I2C(0x27, 16, 2);
	lcd->init();
	lcd->backlight();

    sched.init(50);

    /*creating tasks and add to scheduler*/
    Task* measureLevel = new MeasureLevelTask();
    measureLevel->init(MEASURE_LEVEL_PERIOD);
    sched.addTask(measureLevel);
    Task* detectingMotionTask = new DetectingMotionTask();
    detectingMotionTask->init(DETECTING_MOTION_PERIOD);
    sched.addTask(detectingMotionTask);
    Task* measureTemp = new MeasureTemperatureTask();
    measureTemp->init(MEASURE_TEMPERATURE_PERIOD);
    sched.addTask(measureTemp);
    Task* receiveMsg = new ReceiveMsgTask();
    receiveMsg->init(RECEIVE_MSG_PERIOD);
    sched.addTask(receiveMsg);
    Task* sendMsg = new SendMsgTask();
    sendMsg->init(SEND_MSG_PERIOD);
    sched.addTask(sendMsg);
    Task* wasteDisposalTask = new WasteDisposalTask();
    wasteDisposalTask->init(WASTE_DISPOSAL_TASK_PERIOD);
    sched.addTask(wasteDisposalTask);


}

void loop() {
  sched.schedule();
}