#include "TemperatureSensor.h"
#include "Arduino.h"

TemperatureSensor::TemperatureSensor(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

/**
 * Returns the temperature in celsius degrees.
 */
int TemperatureSensor::getTemp() {
    int reading = analogRead(pin);
    float voltage = reading * (5.0 / 1024.0);
    float temperatureC = (voltage - 0.5) * 100;
    return temperatureC;
}