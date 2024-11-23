#ifndef __ENTERING_WASTE__
#define __ENTERING_WASTE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/WasteDetector.h"
#include <LiquidCrystal_I2C.h>

extern WasteDetector* wasteDetector;
extern bool volatile closePressed;
extern String stateMsg;
extern LiquidCrystal_I2C* lcd;

class EnteringWaste : public State {
    private:
        unsigned long startTime;
    public:
        void init() override;
        State* handle() override;
};

#endif
