#ifndef __SLEEP_STATE__
#define __SLEEP_STATE__

#include "State.h"

class SleepState: public State {
    public:
        SleepState();
        State* handle() override;
};

#endif