#include "DoorController.h"
#include <Arduino.h>
#include "headers/Defines.h"

DoorController::DoorController(PWMServo* actuator) {
    this->servo = actuator;
    this->servo->write(DOOR_CLOSED_ANGLE);
    delay(SWEEP_TIME);
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
        this->servo->write(FRONT_DOOR_OPEN_ANGLE);
        delay(SWEEP_TIME);
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
        this->servo->write(BACK_DOOR_OPEN_ANGLE);
        delay(SWEEP_TIME);
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
        this->servo->write(DOOR_CLOSED_ANGLE);
        delay(SWEEP_TIME);
        return true;
    }
    return false;
}

DoorState DoorController::getCurrentState() {
    return this->currentDoorState;
}
