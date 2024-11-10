#include "WasteReceived.h"

class WasteReceived: public State {
    public:
        WasteReceived() {
            doorController->close();
        }
    State* handle() override {
        return nullptr;
    }
};