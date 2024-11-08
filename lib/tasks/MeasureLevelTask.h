#ifndef __MEASURELEVELTASK__
#define __MEASURELEVELTASK__
#include "Task.h"
#include "WasteDetector.h"

class MeasureLevelTask: public Task {
    private:
        WasteDetector wasteDetector;
    public:
        void tick();
};

#endif