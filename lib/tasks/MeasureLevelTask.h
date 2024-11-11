#ifndef __MEASURELEVELTASK__
#define __MEASURELEVELTASK__
#include "Task.h"
#include "WasteDetector.h"
#include "pins.h"
#include "Defines.h"

extern WasteDetector* wasteDetector;

class MeasureLevelTask: public Task {
    public:
        void tick();
};

#endif