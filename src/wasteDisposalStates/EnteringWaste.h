#ifndef __ENTERING_WASTE__
#define __ENTERING_WASTE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/WasteDetector.h"
#include <LiquidCrystal_I2C.h>

extern WasteDetector* wasteDetector;
extern bool openPressed;
extern bool closePressed;
extern String stateMsg;
extern LiquidCrystal_I2C* lcd;

class EnteringWaste : public State {
    private:
        unsigned long currentTime;
    public:
        EnteringWaste();
        void init() override;
        State* handle() override;
};

#endif
