#include "DoorController.h"
#include "Arduino.h"

DoorController::DoorController() {
    this->doorState = DOOR_CLOSED;
}

void DoorController::attachActuator(Servo* actuator) {
    this->servo = actuator;
    this->doorState = DOOR_CLOSED;
    this->servo->write(90);
    delay(150);
}

void DoorController::detachActuator() {
    delete this->servo;
}

void DoorController::openFront() {
    if (doorState == DOOR_CLOSED) {
        this->servo->write(180);
        delay(150);
        this->doorState = FRONT_OPEN;
    }
}

void DoorController::openBack() {
    if (doorState == DOOR_CLOSED) {
        this->servo->write(0);
        delay(150);
        this->doorState = BACK_OPEN;
    }
}

void DoorController::close() {
    if (doorState == BACK_OPEN || doorState == FRONT_OPEN) {
        this->doorState = DOOR_CLOSED;
        this->servo->write(90);
    }
}

DoorState DoorController::getCurrentState() {
    return this->doorState;
}
