#ifndef __STATE__
#define __STATE__

class State {
    public:
        virtual void init() = 0;
        /**
         * every state should do his own job.
         * @return a new state which could be another state or nullptr if its the same state.
         */
        virtual State* handle() = 0; 
        virtual ~State() {}     
};

#endif