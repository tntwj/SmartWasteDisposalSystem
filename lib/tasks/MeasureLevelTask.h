#ifndef __MEASURELEVELTASK__
#define __MEASURELEVELTASK__
#include "Task.h"
#include "WasteDetector.h"
#include "pins.h"
#include "Defines.h"

WasteDetector* wasteDetector = new WasteDetector(new UltraSoundProxy(ULTRA_SOUND_TRIG_PIN, ULTRA_SOUND_ECHO_PIN), MAX_WASTE_LEVEL, MIN_WASTE_LEVEL);

class MeasureLevelTask: public Task {
    public:
        void tick();
};

#endif