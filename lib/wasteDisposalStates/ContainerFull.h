#ifndef __CONTAINERFULL__
#define __CONTAINERFULL__

#include "State.h"
#include "SleepState.h"

class ContainerFull : public State {
    public:
        ContainerFull();
        State* handle() override;
};

#endif
