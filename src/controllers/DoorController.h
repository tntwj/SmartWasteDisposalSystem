#include <PWMServo.h>

#ifndef __DOOR_CONTROLLER__
#define __DOOR_CONTROLLER__

enum DoorState {
    FRONT_OPEN, BACK_OPEN, DOOR_CLOSED
};

class DoorController {
    public:
        DoorController(PWMServo* actuator);
        ~DoorController();
        bool openFront();
        bool openBack();
        bool close();
        DoorState getCurrentState();
    private:
        PWMServo* servo;
        DoorState currentDoorState;
};

#endif
