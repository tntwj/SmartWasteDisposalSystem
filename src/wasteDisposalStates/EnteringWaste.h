#ifndef __ENTERINGWASTE__
#define __ENTERINGWASTE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/WasteDetector.h"
#include "controllers/ButtonPadController.h"

extern WasteDetector* wasteDetector;

class EnteringWaste : public State {
    private:
    int count = 0;
    int limit = ENTERING_WASTE_PERIOD / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        EnteringWaste();
        void init() override;
        State* handle() override;
};

#endif
