#include "TemperatureSensor.h"
#include "Arduino.h"

// Could add farenheit return

TemperatureSensor::TemperatureSensor(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

int TemperatureSensor::readTemperature() {
    int reading = analogRead(pin);
    float voltage = reading * (5.0 / 1024.0);
    float temperatureC = (voltage - 0.5) * 100;
    return temperatureC;
}
