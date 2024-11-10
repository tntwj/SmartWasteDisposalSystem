#include "ContainerFull.h"

class ContainerFull: public State {
    public:
        ContainerFull() {
            ledController->switchOffGreen();
            ledController->switchOnRed();
            doorController->close();
        }
    State* handle() override{
        return nullptr;
    }

};