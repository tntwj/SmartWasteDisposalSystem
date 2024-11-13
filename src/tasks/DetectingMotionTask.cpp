#include "DetectingMotionTask.h"
#include <Arduino.h>

void DetectingMotionTask::tick() {
    motionDetector->sense();
}