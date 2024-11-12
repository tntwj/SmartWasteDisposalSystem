#include "MeasureTemperatureTask.h"
#include <Arduino.h>
void MeasureTemperatureTask::tick() {
    tempController->readTemp();
}