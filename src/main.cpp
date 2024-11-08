#include <Arduino.h>
#include "defines.h"
#include "Scheduler.h"
#include "MeasureLevelTask.h"
#include "MeasureTemperatureTask.h"
#include "WasteDisposalTask.h"

Scheduler sched;

void setup() {
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
