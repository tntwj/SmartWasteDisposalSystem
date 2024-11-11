#ifndef __MSG_SERVICE__
#define __MSG_SERVICE__

#include <Arduino.h>

class Msg {
    public:
        Msg(String content) {
            this->content = content;
        }

        String getContent() {
            return this->content;
        }
    private:
        String content;
};

class Pattern {
    public:
        virtual boolean match(const Msg& m) = 0;  
};

class MsgServiceClass {
    public:
        void init();
        bool isMsgAvailable();
        Msg* receiveMsg();
        bool isMsgAvailable(Pattern& pattern);
        Msg* receiveMsg(Pattern& pattern);
        void sendMsg(const Msg& msg);
        void sendMsg(const String& msg);
        Msg* currentMsg;
        bool msgAvailable;
};

extern MsgServiceClass MsgService;

#endif
