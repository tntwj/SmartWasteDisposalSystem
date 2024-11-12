#include "SendMsgTask.h"

void SendMsgTask::tick() {
    MsgService.sendMsg("STATE:" + String(stateMsg) + "|TEMP:" + String(tempController->getTemp()) + "|LEVEL:" + String(wasteDetector->getLevel()));
}