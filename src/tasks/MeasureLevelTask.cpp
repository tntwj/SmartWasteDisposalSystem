#include "MeasureLevelTask.h"

void MeasureLevelTask::tick() {
    wasteDetector->readLevel();
}