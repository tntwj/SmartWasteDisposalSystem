#include "ContainerFull.h"

class ContainerFull: public State {
    public:
        ContainerFull() {

        }
    State* handle() override{
        return nullptr;
    }

};