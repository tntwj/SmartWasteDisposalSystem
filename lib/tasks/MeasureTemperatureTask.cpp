#include <MeasureTemperatureTask.h>

void MeasureTemperatureTask::tick() {
    tempController->readTemp();
}