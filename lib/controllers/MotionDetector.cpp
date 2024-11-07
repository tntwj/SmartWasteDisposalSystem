#include "MotionDetector.h"

MotionDetector::MotionDetector() {
    this->detected = false;
}

void MotionDetector::attachSensor(PirSensor* sensor) {
    this->sensor = sensor;
}

void MotionDetector::detect() {
    delete this->sensor;
}

void MotionDetector::detect() {
    this->detected = this->sensor->detect();
}

bool MotionDetector::hasDetected() {
    return this->detected;
}
