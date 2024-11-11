#ifndef __DANGEROUSTEMP__
#define __DANGEROUSTEMP__

#include "State.h"

class DangerousTemp: public State {
    public:
        DangerousTemp();
        State* handle() override;
};

#endif