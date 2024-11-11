#include "WasteDetector.h"
#include <Defines.h>
#include <Arduino.h>

WasteDetector::WasteDetector(UltraSoundProxy* sensor, float maxDistance, float minDistance) {
    this->proxySensor = sensor;
    this->maxDistance = maxDistance;
    this->minDistance = minDistance;
    this->distance = 0.0f;
    this->wasteLevel = 0.0f;
}

WasteDetector::~WasteDetector() {
    delete this->proxySensor;
}

/**
 * Reads the distance and level.
 */
void WasteDetector::readLevel() {
    this->distance = this->proxySensor->getDistance();
    if (this->distance < this->minDistance) {
        this->wasteLevel = 1.0f;
    } else if (this->distance > this->maxDistance) {
        this->wasteLevel = 0.0f;
    } else {
        this->wasteLevel = constrain(1.0f - (this->distance - this->minDistance) / (this->maxDistance - this->minDistance), 0.0f, 1.0f);
    }
}

/**
 * Returns the latest read distance. In order to get the latest value readLevel() should be called first.
 */
float WasteDetector::getDistance() {
    return this->distance;
}

/**
 * Returns the latest read value. In order to get the latest value readLevel() should be called first.
 */
float WasteDetector::getLevel() {
    return this->wasteLevel;
}

bool WasteDetector::isFull() {
    return wasteLevel >= 1;
}
