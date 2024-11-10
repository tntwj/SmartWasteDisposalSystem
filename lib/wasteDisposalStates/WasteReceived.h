#ifndef __WASTERECEIVED__
#define __WASTERECEIVED__

#include "State.h"
#include "Idle.h"

class WasteReceived : public State {
    public:
        WasteReceived();
        State* handle() override;
};

#endif
