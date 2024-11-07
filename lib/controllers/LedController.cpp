#include "LedController.h"

LedController::LedController() {
}

void LedController::attachGreenLed(Led* led) {
    this->greenLed = led;
}

void LedController::attachRedLed(Led* led) {
    this->redLed = led;
}

void LedController::detachAll() {
    delete greenLed;
    delete redLed;
}

void LedController::switchOnRed() {
    this->redLed->switchOn();
}

void LedController::switchOffRed() {
    this->redLed->switchOff();
}

void LedController::switchOnGreen() {
    this->greenLed->switchOn();
}

void LedController::switchOffGreen() {
    this->greenLed->switchOff();
}

bool LedController::isRedOn() {
    return this->redLed->isOn();
};

bool LedController::isGreenOn() {
    return this->greenLed->isOn();
}
