#ifndef __DOOR_CONTROLLER__
#define __DOOR_CONTROLLER__

#include "Servo.h"

enum DoorState {
    FRONT_OPEN, BACK_OPEN, DOOR_CLOSED
};

class DoorController {
    public:
        DoorController();
        void attachActuator(Servo* actuator);
        void detachActuator();
        void openFront();
        void openBack();
        void close();
        DoorState getCurrentState();
    private:
        Servo* servo;
        DoorState doorState;
};

#endif