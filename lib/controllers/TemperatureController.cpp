#include "TemperatureController.h"
#include "defines.h"

TemperatureController::TemperatureController() {
    this->currentTemp = 0;
}

void TemperatureController::attachSensor(TemperatureSensor* sensor) {
    this->tempSensor = sensor;
}

void TemperatureController::detachSensor() {
    delete this->tempSensor;
}

void TemperatureController::readTemp() {
    this->currentTemp = this->tempSensor->readTemperature();
}

bool TemperatureController::isTemperatureHigh() {
    return this->currentTemp >= TEMPERATURE_THRESHOLD;
}
