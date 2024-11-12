#ifndef __ENTERINGWASTE__
#define __ENTERINGWASTE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/WasteDetector.h"

extern WasteDetector* wasteDetector;
extern bool openPressed;
extern bool closePressed;
extern String stateMsg;

class EnteringWaste : public State {
    private:
    unsigned long currentTime;
    public:
        EnteringWaste();
        void init() override;
        State* handle() override;
};

#endif
