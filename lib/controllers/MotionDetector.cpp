#include "MotionDetector.h"

MotionDetector::MotionDetector(PirSensor* sensor) {
    this->pirSensor = sensor;
    this->detected = false;
}

MotionDetector::~MotionDetector() {
    delete this->pirSensor;
}

/**
 * Attempts to sense anything that moves.
 */
void MotionDetector::sense() {
    this->detected = this->pirSensor->sense();
}

/**
 * Returns the latest reading. In order to get the latest value sense() should be called first.
 */
bool MotionDetector::hasDetected() {
    return this->detected;
}
