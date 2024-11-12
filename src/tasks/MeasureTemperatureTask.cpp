#include "MeasureTemperatureTask.h"
#include <Arduino.h>
void MeasureTemperatureTask::tick() {
    Serial.println("temperature: " + String(tempController->getTemp()));
    tempController->readTemp();
}