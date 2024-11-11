#ifndef __MEASURELEVELTASK__
#define __MEASURELEVELTASK__

#include "Task.h"
#include "controllers/WasteDetector.h"

extern WasteDetector* wasteDetector;

class MeasureLevelTask: public Task {
    public:
        void tick();
};

#endif