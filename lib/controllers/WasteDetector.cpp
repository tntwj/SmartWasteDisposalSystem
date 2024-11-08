#include "WasteDetector.h"
#include "Defines.h"
#include "Arduino.h"

WasteDetector::WasteDetector(UltraSoundProxy* sensor) {
    this->proxySensor = sensor;
    this->wasteLevel = 0.0f;
}

WasteDetector::~WasteDetector() {
    delete this->proxySensor;
}

/**
 * Reads the current level.
 */
void WasteDetector::readLevel() {
    float readValue = this->proxySensor->getDistance();
    this->wasteLevel = readValue / (MAX_WASTE_LEVEL - MIN_WASTE_LEVEL);
}

/**
 * Returns the latest read value. In order to get the latest value readLevel() should be called first.
 */
float WasteDetector::getLevel() {
    return this->wasteLevel;
}

bool WasteDetector::isFull() {
    return wasteLevel >= 1.0f;
}
