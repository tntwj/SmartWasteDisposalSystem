#include "State.h"

class Idle: public State {
    Idle() {
        ledController->switchOnGreen();
    }

    State* handle() {
        return nullptr;
    }
};
