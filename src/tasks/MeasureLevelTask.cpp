#include "MeasureLevelTask.h"
#include <Arduino.h>

void MeasureLevelTask::tick() {
    wasteDetector->readLevel();
}