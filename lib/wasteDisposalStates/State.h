#ifndef __STATE__
#define __STATE__

class State{
    public:
        /**
     * the actions to be done when the concrete state is istantiated.
     */
    virtual void init();
    /**
     * every state should do his own job.
     * @return a new state which could be another state or nullptr if its the same state.
     */
    virtual State* handle();
};
#endif