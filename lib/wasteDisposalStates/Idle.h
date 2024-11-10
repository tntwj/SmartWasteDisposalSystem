#ifndef __IDLE__
#define __IDLE__

#include "State.h"
#include "EnteringWaste.h"

class Idle : public State {
    public:
        Idle();
        State* handle() override;
};

#endif
