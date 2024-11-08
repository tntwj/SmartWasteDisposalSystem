#ifndef __DOOR_CONTROLLER__
#define __DOOR_CONTROLLER__

#include "Servo.h"

enum DoorState {
    FRONT_OPEN, BACK_OPEN, DOOR_CLOSED
};

class DoorController {
    public:
        DoorController(Servo* actuator);
        ~DoorController();
        bool openFront();
        bool openBack();
        bool close();
        DoorState getCurrentState();
    private:
        Servo* servo;
        DoorState currentDoorState;
};

#endif
