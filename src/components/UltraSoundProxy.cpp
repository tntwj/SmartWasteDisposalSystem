#include <Arduino.h>
#include "UltraSoundProxy.h"

/* Assuming an ambient temperature of 20 degree celsius */
const float vs = 331.5 + 0.6*20;

UltraSoundProxy::UltraSoundProxy(int trigPin, int echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float UltraSoundProxy::getDistance() {
    /* Sending the pulse */
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);

    /* Receiving the echo */
    float tUS = pulseIn(echoPin, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float distance = t*vs;
    return distance;
}