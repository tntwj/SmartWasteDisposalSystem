#include "State.h"

class SleepState: public State {
    public:
        SleepState();
        State* handle() override;
};