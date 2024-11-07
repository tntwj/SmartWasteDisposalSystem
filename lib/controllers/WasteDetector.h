#ifndef __WASTE_DETECTOR__
#define __WASTE_DETECTOR__

#include "UltraSoundProxy.h"

class WasteDetector {
    public:
        WasteDetector();
        void attachSensor(UltraSoundProxy* sensor);
        void detachSensor();
        void readLevel();
        float getLevel();
        bool isFull();
    
    private:
        UltraSoundProxy* sensor;
        float wasteLevel;
};
    
#endif