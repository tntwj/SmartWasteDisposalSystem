#include "WasteDetector.h"
#include "Defines.h"
#include "Arduino.h"

WasteDetector::WasteDetector() {
    this->wasteLevel = 0.0;
}

void WasteDetector::attachSensor(UltraSoundProxy* sensor) {
    this->sensor = sensor;
}

void WasteDetector::detachSensor() {
    delete this->sensor;
}

void WasteDetector::readLevel() {
    float readValue = this->sensor->getDistance();
    this->wasteLevel = readValue / (abs(MAX_WASTE_LEVEL) + abs(MIN_WASTE_LEVEL));
}

float WasteDetector::getLevel() {
    return this->wasteLevel;
}

bool WasteDetector::isFull() {
    return wasteLevel >= 1.0;
}
