#include "MeasureLevelTask.h"
#include "WasteDisposalTask.h"

void MeasureLevelTask::tick() {
    wasteDetector->readLevel();
}