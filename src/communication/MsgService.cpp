#include "MsgService.h"

static const String INIT_MESSAGE = "ArduinoUno";

String content;

MsgServiceClass MsgService;

bool MsgServiceClass::isMsgAvailable() {
    return this->msgAvailable;
}

Msg* MsgServiceClass::receiveMsg() {
    if (this->msgAvailable) {
        Msg* msg = this->currentMsg;
        this->msgAvailable = false;
        this->currentMsg = nullptr;
        content = "";
        return msg;
    } else {
        return nullptr;
    }
}

void MsgServiceClass::init() {
    Serial.begin(9600);
    Serial.println(INIT_MESSAGE);
    content.reserve(256);
    content = "";
    this->currentMsg = nullptr;
    this->msgAvailable = false;
}

void MsgServiceClass::sendMsg(const String& msg) {
    Serial.println(msg);
}

void serialEvent() {
    /* reading the content */
    while (Serial.available()) {
        char ch = (char) Serial.read();
        if (ch == '\n') {
            MsgService.currentMsg = new Msg(content);
            MsgService.msgAvailable = true;
        } else {
            content += ch;
        }
    }
}
