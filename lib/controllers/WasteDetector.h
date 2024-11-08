#ifndef __WASTE_DETECTOR__
#define __WASTE_DETECTOR__

#include "UltraSoundProxy.h"

class WasteDetector {
    public:
        WasteDetector(UltraSoundProxy* sensor);
        ~WasteDetector();
        void readLevel();
        float getLevel();
        bool isFull();
    
    private:
        UltraSoundProxy* proxySensor;
        float wasteLevel;
};
    
#endif
