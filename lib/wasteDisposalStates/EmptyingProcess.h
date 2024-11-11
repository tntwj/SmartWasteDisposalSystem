#ifndef __EMPTYINGPROCESS__
#define __EMPTYINGPROCESS__

#include <State.h>

class EmptyingProcess : public State {
    public:
        EmptyingProcess();
        State* handle() override;
};

#endif
