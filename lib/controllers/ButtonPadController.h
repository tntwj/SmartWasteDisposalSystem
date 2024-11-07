#ifndef __BUTTON_PAD_CONTROLLER__
#define __BUTTON_PAD_CONTROLLER__

#include "Button.h"

class ButtonPadController {
    public:
        ButtonPadController();
        void attachOpenButton(Button* openButton);
        void attachCloseButton(Button* closeButton);
        void detachAll();
        void readOpenButtonState();
        void readCloseButtonState();
        bool getOpenButtonState();
        bool getCloseButtonState();
    private:
        Button* openButton;
        Button* closeButton;
        bool isOpenPressed;
        bool isClosePressed;
};

#endif
