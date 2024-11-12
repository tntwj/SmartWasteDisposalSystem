#ifndef __RECEIVEMSG__
#define __RECEIVEMSG__
#include "communication/MsgService.h"
#include "Task.h"

extern MsgServiceClass MsgService;

class ReceiveMsgTask: public Task {
    public:
        void tick();
};
#endif