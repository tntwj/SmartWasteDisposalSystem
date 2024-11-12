#ifndef __IDLE__
#define __IDLE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"

extern LedController* ledController;

class Idle : public State {
    private:
    /**using simplest count version to switch states.
     * @TODO to be optimized
    */
    int count = 0;
    int limit = 5;
    public:
        Idle();
        void init() override;
        State* handle() override;
};

#endif
