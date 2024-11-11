#include <EnteringWaste.h>
#include <Defines.h>
#include <WasteDisposalTask.h>
#include <ContainerFull.h>
#include <WasteReceived.h>
#include <MeasureLevelTask.h>

class EnteringWaste: public State {
    private:
        int count = 0;
        int limit = ENTERING_WASTE_PERIOD / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        EnteringWaste() {
            doorController->openFront();
        }

    State* handle() override{
        count++;
        if (wasteDetector->getLevel() >= MAX_WASTE_LEVEL) {
            count = 0;
            return new ContainerFull();
        }
        if (buttonPadController->isClosePressed() || count >= limit) {
            count = 0;
            return new WasteReceived();
        }
        return nullptr;
    }
};