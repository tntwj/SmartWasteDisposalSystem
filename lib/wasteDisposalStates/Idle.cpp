#include "State.h"
#include "EnteringWaste.cpp"

class Idle: public State {
    public:
        Idle() {
            ledController->switchOnGreen();
        }

    State* handle() override{
        if (buttonPadController->isOpenPressed()) {
            return new EnteringWaste();
        }
        return nullptr;
    }
};
