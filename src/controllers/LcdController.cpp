#include "LcdController.h"

LcdController::LcdController(LiquidCrystal_I2C* lcd) {
    this->lcd = lcd;
    this->lcd->init();
	this->lcd->backlight();
}

LiquidCrystal_I2C* LcdController::getLcd() {
    return this->lcd;
}

void LcdController::turnOff() {
    this->lcd->noBacklight();
    this->lcd->noDisplay();
}

void LcdController::turnOn() {
    this->lcd->display();
    this->lcd->backlight();
}

void LcdController::printWasteReceivedMessage() {
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("WASTE RECEIVED");
}

void LcdController::printIdleMessage() {
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("PRESS OPEN TO");
    this->lcd->setCursor(0, 1);
    this->lcd->print("ENTER THE WASTE");
}

void LcdController::printEnteringWasteMessage() {
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("PRESS CLOSE");
    this->lcd->setCursor(0, 1);
    this->lcd->print("WHEN DONE");
}

void LcdController::printEmptyingMessage() {
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("EMPTYING");
    this->lcd->setCursor(0, 1);
    this->lcd->print("PROCESS");
}

void LcdController::printDangerousTempMessage() {
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("PROBLEM DETECTED");
}

void LcdController::printContainerFullMessage() {
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("CONTAINER FULL");
}