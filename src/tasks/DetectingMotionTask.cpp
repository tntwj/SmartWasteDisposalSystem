#include "DetectingMotionTask.h"

void DetectingMotionTask::tick() {
    motionDetector->sense();
}