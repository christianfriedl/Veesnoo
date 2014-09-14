#include <unistd.h>
#include <ncursesw/ncurses.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Widget.h"
#// include "KeyReceiving.h"
// #include "SingleFocusManager.h"
#include "Button.h"

namespace nv {

Button::Button(const std::string& text, int x, int y): Widget(Rect(x, y, text.size() + 4, 1)), text_(text), state_(ButtonState_normal) {
    // focusManager = new SingleFocusManager(this); 
}

void Button::refresh() {
    if (state_ == ButtonState_pushed)
        cw->attrOn(A_REVERSE);
    std::stringstream s; 
    s << "[ " << text_ << " ]";
    addString(s.str(), 0, 0);
    if (state_ == ButtonState_pushed)
        cw->attrOff(A_REVERSE);
    Widget::refresh();
}

void Button::switchState() {
    if (state_ == ButtonState_pushed)
        state_ = ButtonState_normal;
    else
        state_ = ButtonState_pushed;
}

bool Button::receiveKey(int ch) {
    if (ch == ' ' || ch == 13) {
        switchState();
        // Todo do stuff
        switchState();
        return true;
    }
    return false;
}

}

