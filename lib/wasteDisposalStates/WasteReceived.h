#ifndef __WASTERECEIVED__
#define __WASTERECEIVED__

class WasteReceived : public State {
    public:
        WasteReceived();
        State* handle() override;
};

#endif
