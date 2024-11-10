#ifndef __DANGEROUSTEMP__
#define __DANGEROUSTEMP__
#include "State.h"
#include "MeasureTemperatureTask.h"

class DangerousTemp: public State {
    public:
        DangerousTemp();
        State* handle() override;
};

#endif