#include "ButtonPadController.h"    
    
ButtonPadController::ButtonPadController() {
    this->isOpenPressed = false;
    this->isClosePressed = false;
}

void ButtonPadController::attachOpenButton(Button* openButton) {
    this->openButton = openButton;
}

void ButtonPadController::attachCloseButton(Button* closeButton) {
    this->closeButton = closeButton;
}

void ButtonPadController::detachAll() {
    delete this->openButton;
    delete this->closeButton;
}

void ButtonPadController::readOpenButtonState() {
    this->openButton->isPressed() ? isOpenPressed = true : isOpenPressed = false;
}

void ButtonPadController::readCloseButtonState() {
    this->closeButton->isPressed() ? isClosePressed = true : isClosePressed = false;
}

bool ButtonPadController::getOpenButtonState() {
    return this->isOpenPressed;
}

bool ButtonPadController::getCloseButtonState() {
    return this->isClosePressed;
}
