#ifndef __ENTERING_WASTE__
#define __ENTERING_WASTE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/WasteDetector.h"
#include "controllers/LcdController.h"

extern WasteDetector* wasteDetector;
extern LcdController* lcdController;
extern bool volatile closePressed;
extern String stateMessage;

class EnteringWaste : public State {
    private:
        unsigned long startTime;
    public:
        void execute() override;
        State* next() override;
};

#endif
