#include "EnteringWaste.h"


class EnteringWaste: public State{
    public:
        EnteringWaste() {
            doorController->openFront();
        }

    State* handle() override{
        if (wasteDetector->getLevel() >= MAX_WASTE_LEVEL) {
            return new ContainerFull();
        }
        if (buttonPadController->isClosePressed()) {
            return new WasteReceived();
        }
        return nullptr;
    }
};