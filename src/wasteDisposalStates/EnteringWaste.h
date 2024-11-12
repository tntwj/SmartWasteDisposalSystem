#ifndef __ENTERINGWASTE__
#define __ENTERINGWASTE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/WasteDetector.h"
#include "controllers/ButtonPadController.h"

extern WasteDetector* wasteDetector;
extern ButtonPadController* buttonPadController;

class EnteringWaste : public State {
    private:
    unsigned long currentTime;
    public:
        EnteringWaste();
        void init() override;
        State* handle() override;
};

#endif
