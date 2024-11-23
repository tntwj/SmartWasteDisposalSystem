#include <ServoTimer2.h>

#ifndef __DOOR_CONTROLLER__
#define __DOOR_CONTROLLER__

enum DoorState {
    FRONT_OPEN, BACK_OPEN, DOOR_CLOSED
};

class DoorController {
    public:
        DoorController(ServoTimer2* actuator, int pin);
        ~DoorController();
        bool openFront();
        bool openBack();
        bool close();
        DoorState getCurrentState();
    private:
        ServoTimer2* servo;
        DoorState currentDoorState;
};

#endif
