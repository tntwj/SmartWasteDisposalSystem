#ifndef __WASTE_DISPOSAL_TASK__
#define __WASTE_DISPOSAL_TASK__

#include "Task.h"
#include "wasteDisposalStates/State.h"
#include "controllers/TemperatureController.h"

extern TemperatureController* tempController;
extern bool restorePressed;

class WasteDisposalTask: public Task {
    private:
        State* currentState;
        State* stateBeforeHighTemp;
        bool isInDangerousTempState;

    public:
        WasteDisposalTask();
        void tick() override;
};

#endif
