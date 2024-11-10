#include "State.h"
#include "WasteReceived.cpp"

class EnteringWaste: public State{
    public:
        EnteringWaste() {
            doorController->openFront();
        }

    State* handle() override{
        if (buttonPadController->isClosePressed()) {
            return new WasteReceived();
        }
        return nullptr;
    }
};