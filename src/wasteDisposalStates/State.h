#ifndef __STATE__
#define __STATE__

#include <Arduino.h>

class State {
    public:
        virtual void execute() = 0;
        /**
         * Every state should do its own job.
         * @return a new state which could be another state or nullptr if it does not need to change.
         */
        virtual State* next() = 0; 
        virtual ~State() {}     
};

#endif
