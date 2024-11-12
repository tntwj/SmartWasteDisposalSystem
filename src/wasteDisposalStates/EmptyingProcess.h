#ifndef __EMPTYINGPROCESS__
#define __EMPTYINGPROCESS__

#include "headers/Defines.h"
#include "State.h"
#include "controllers/DoorController.h"
#include "controllers/LedController.h"

extern LedController* ledController;
extern DoorController* doorController;

class EmptyingProcess : public State {
    private:
    /**using simplest count version to switch states.
     * @TODO to be optimized
    */
    int count = 0;
    int limit = EMPTYING_PROCESS / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        EmptyingProcess();
        void init() override;
        State* handle() override;
};

#endif
