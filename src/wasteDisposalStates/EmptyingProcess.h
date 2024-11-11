#ifndef __EMPTYINGPROCESS__
#define __EMPTYINGPROCESS__
#include "headers/Defines.h"
#include "State.h"

class EmptyingProcess : public State {
    private:
    /**using simplest count version to switch states.
     * @TODO to be optimized
    */
    int count = 0;
    int limit = EMPTYING_PROCESS / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        EmptyingProcess();
        State* handle() override;
};

#endif
