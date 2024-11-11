#ifndef __CONTAINERFULL__
#define __CONTAINERFULL__

#include "State.h"
#include "headers/Defines.h"

class ContainerFull : public State {
    private:
        /**using simplest count version to switch states.
         * @TODO to be optimized
        */
        int count = 0;
        int limit = WASTE_RECEIVED_PERIOD / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        ContainerFull();
        void init() override;
        State* handle() override;
};

#endif
