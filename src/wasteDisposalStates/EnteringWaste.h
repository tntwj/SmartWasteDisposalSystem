#ifndef __ENTERINGWASTE__
#define __ENTERINGWASTE__

#include "State.h"
#include "headers/Defines.h"

class EnteringWaste : public State {
    private:
    int count = 0;
    int limit = ENTERING_WASTE_PERIOD / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        EnteringWaste();
        State* handle() override;
};

#endif
