#include <unistd.h>
#include <ncursesw/ncurses.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Widget.h"
#// include "KeyReceiving.h"
#include "Button.h"

namespace nv {

Button::Button(const std::string& text, int x, int y): FocusableWidget(Rect(x, y, text.size() + 4, 1)), text_(text), state_(ButtonState_normal) {
}

void Button::refresh() {
    if ( isFocused() || state_ == ButtonState_pushed)
        cw->attrOn(A_REVERSE);
    std::stringstream s; 
    s << "[ " << text_ << " ]";
    addString(s.str(), 0, 0);
    if ( isFocused() || state_ == ButtonState_pushed)
        cw->attrOff(A_REVERSE);
    FocusableWidget::refresh();
}

bool Button::push() {
    state_ = ButtonState_pushed;
    // TODO do stuff
    refresh();
    state_ = ButtonState_normal;
    refresh();
    return true;
}

bool Button::receiveKey(int ch) {
    if (ch == ' ' || ch == 13) {
        return push();
    }
    return false;
}

}

