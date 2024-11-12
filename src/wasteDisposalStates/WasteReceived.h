#ifndef __WASTERECEIVED__
#define __WASTERECEIVED__

#include "headers/Defines.h"
#include "State.h"
#include "controllers/DoorController.h"

extern DoorController* doorController;

class WasteReceived : public State {
    private:
    /**using simplest count version to switch states.
     * @TODO to be optimized
    */
    int count = 0;
    int limit = WASTE_RECEIVED_PERIOD / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        WasteReceived();
        void init() override;
        State* handle() override;
};

#endif
