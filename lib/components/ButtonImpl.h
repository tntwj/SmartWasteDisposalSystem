#ifndef __BUTTON_IMPL__
#define __BUTTON_IMPL__

class ButtonImpl {
    public:
        ButtonImpl(int pin);
        bool isPressed();
    private:
        int pin;
};

#endif