#include "PirSensor.h"
#include "Arduino.h"

PirSensor::PirSensor(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

boolean PirSensor::hasDetected() {
    return digitalRead(pin) == HIGH;
}