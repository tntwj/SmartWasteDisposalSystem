#ifndef __WASTE_DISPOSAL_TASK__
#define __WASTE_DISPOSAL_TASK__

#include "Task.h"
#include "wasteDisposalStates/State.h"
#include "controllers/TemperatureController.h"
#include "controllers/MotionDetector.h"
#include "controllers/DoorController.h"
#include "controllers/LedController.h"
#include "wasteDisposalStates/Idle.h"

extern MotionDetector* motionDetector;
extern DoorController* doorController;
extern LedController* ledController;
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
