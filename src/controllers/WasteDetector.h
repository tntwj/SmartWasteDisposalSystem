#ifndef __WASTE_DETECTOR__
#define __WASTE_DETECTOR__

#include "components/UltraSoundProxy.h"

class WasteDetector {
    public:
        WasteDetector(UltraSoundProxy* sensor, float maxDistance, float minDistance);
        ~WasteDetector();
        void readLevel();
        float getDistance();
        float getLevel();
        bool isFull();
    
    private:
        UltraSoundProxy* proxySensor;
        float distance;
        float maxDistance;
        float minDistance;
        float wasteLevel;
};
    
#endif
