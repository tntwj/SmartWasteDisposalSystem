#ifndef __ENTERINGWASTE__
#define __ENTERINGWASTE__

#include "State.h"

class EnteringWaste : public State {
    public:
        EnteringWaste();
        State* handle() override;
};

#endif
