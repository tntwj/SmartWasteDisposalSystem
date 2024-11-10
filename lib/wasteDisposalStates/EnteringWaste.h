#ifndef __ENTERINGWASTE__
#define __ENTERINGWASTE__

#include "State.h"
#include "WasteReceived.h"
#include "ContainerFull.h"
#include "MeasureLevelTask.h"

class EnteringWaste : public State {
    public:
        EnteringWaste();
        State* handle() override;
};

#endif
