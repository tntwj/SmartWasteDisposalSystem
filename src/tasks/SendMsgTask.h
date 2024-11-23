#ifndef __SEND_MSG_TASK__
#define __SEND_MSG_TASK__

#include "communication/MsgService.h"
#include "Task.h"
#include "controllers/TemperatureController.h"
#include "controllers/WasteDetector.h"

extern MsgServiceClass MsgService;
extern TemperatureController* tempController;
extern WasteDetector* wasteDetector;
extern String stateMsg;

class SendMsgTask: public Task {
    public:
        void tick() override;
};

#endif
