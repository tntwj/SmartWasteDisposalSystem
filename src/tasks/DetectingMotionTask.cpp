#include "DetectingMotionTask.h"
#include <Arduino.h>

void DetectingMotionTask::tick() {
    motionDetector->sense();
    Serial.println("motion detected: " + String(motionDetector->hasDetected()));

}