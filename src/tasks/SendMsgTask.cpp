#include "SendMsgTask.h"

void SendMsgTask::tick() {
    if (!MsgService.isMsgAvailable()) {
        MsgService.sendMsg(
            "STATE:" + String(stateMsg) 
            + "|TEMP:" + String(tempController->getTemp()) 
            + "|LEVEL:" + String(wasteDetector->getLevel())
        );
    }
}