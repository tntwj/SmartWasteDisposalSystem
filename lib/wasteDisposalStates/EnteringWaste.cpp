#include "State.h"

class EnteringWaste: public State{
    EnteringWaste() {
        doorController->openFront();
    }

    State* handle() {
        return nullptr;
    }
};