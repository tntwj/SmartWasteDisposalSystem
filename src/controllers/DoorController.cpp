#include "DoorController.h"
#include <Arduino.h>
#include "headers/Defines.h"

DoorController::DoorController(ServoTimer2* actuator, int pin) {
    this->servo = actuator;
    this->servo->attach(pin);
    this->servo->write(DOOR_CLOSED_WIDTH);
    this->currentDoorState = DOOR_CLOSED;
}

DoorController::~DoorController() {
    delete this->servo;
}

/**
 * Attempts to open the front door. Returns true if successful, false otherwise.
 */
bool DoorController::openFront() {
    if (currentDoorState == DOOR_CLOSED) {
        this->servo->write(FRONT_DOOR_OPEN_WIDTH);
        this->currentDoorState = FRONT_OPEN;
        return true;
    }
    return false;
}

/**
 * Attempts to open the back door. Returns true if successful, false otherwise.
 */
bool DoorController::openBack() {
    if (currentDoorState == DOOR_CLOSED) {
        this->servo->write(BACK_DOOR_OPEN_WIDTH);
        this->currentDoorState = BACK_OPEN;
        return true;
    }
    return false;
}

/**
 * Attempts to close door. Returns true if successful, false otherwise.
 */
bool DoorController::close() {
    if (currentDoorState == BACK_OPEN || currentDoorState == FRONT_OPEN) {
        this->currentDoorState = DOOR_CLOSED;
        this->servo->write(DOOR_CLOSED_WIDTH);
        return true;
    }
    return false;
}

DoorState DoorController::getCurrentState() {
    return this->currentDoorState;
}
