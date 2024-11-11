#ifndef __BUTTON_PAD_CONTROLLER__
#define __BUTTON_PAD_CONTROLLER__

class ButtonPadController {
    public:
        ButtonPadController(int openButtonPin, int closeButtonPin);
        void init();
        bool isOpenPressed();
        bool isClosePressed();
    private:
        static ButtonPadController* instance;
        static void openButtonISR();
        static void closeButtonISR();
        void setOpenPressed(bool pressed);
        void setClosePressed(bool pressed);
        bool openPressed;
        bool closePressed;
        int openPin;
        int closePin;
};

#endif
