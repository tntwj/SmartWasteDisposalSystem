#include "State.h"

class EnteringWaste: public State{
    public:
        EnteringWaste() {
            doorController->openFront();
        }

    State* handle() override{
        return nullptr;
    }
};