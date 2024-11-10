#include "EmptyingProcess.h"

class EmptyingProcess: public State {
    public:
        EmptyingProcess() {
            doorController->openBack();
        }
    State* handle() override{
        return nullptr;
    }
    
};