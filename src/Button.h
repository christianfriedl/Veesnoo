#ifndef NV_BUTTON_H
#define NV_BUTTON_H

#include <string>
#include "FocusableWidget.h"

namespace nv {

typedef enum { ButtonState_normal, ButtonState_pushed } ButtonState;

class Button: public FocusableWidget { // , public KeyReceiving {
public:
    Button(const std::string& text, int x, int y);
    void refresh();
    bool push(); 
    virtual bool receiveKey(int ch);

private:
    std::string text_;
    ButtonState state_;

};

}

#endif
