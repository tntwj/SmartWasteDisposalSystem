#ifndef __MEASURE_LEVEL_TASK__
#define __MEASURE_LEVEL_TASK__

#include "Task.h"
#include "controllers/WasteDetector.h"

extern WasteDetector* wasteDetector;

class MeasureLevelTask: public Task {
    public:
        void tick();
};

#endif
