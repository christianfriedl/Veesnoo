#include <unistd.h>
#include <ncursesw/ncurses.h>
#include <string>
#include <iostream>
#include <sstream>
#include <string.h>
#include "Widget.h"
#// include "KeyReceiving.h"
#include "SingleFocusManager.h"
#include "Checkbox.h"

namespace nv {

Checkbox::Checkbox(int x, int y): FocusableWidget(Rect(x, y, 3, 1)), state_(CheckboxState_unchecked), frame_("[]") {
}

void Checkbox::setFrame(const std::string& frame) {
    frame_ = frame;
}

void Checkbox::refresh() {
    if ( isFocused() )
        cw->attrOn(A_REVERSE);
    char c = (state_ == CheckboxState_checked ? 'x' : ' ');
    std::stringstream s; 
    s << frame_[0] << c << frame_[1];
    addString(s.str(), 0, 0);
    if ( isFocused() )
        cw->attrOff(A_REVERSE);
    FocusableWidget::refresh();
}

bool Checkbox::push() {
    state_ = (state_ == CheckboxState_checked ? CheckboxState_unchecked : CheckboxState_checked);
    // TODO do stuff
    refresh();
    return true;
}

bool Checkbox::isChecked() {
    return state_ == CheckboxState_checked;
}

bool Checkbox::receiveKey(int ch) {
    if (ch == ' ' || ch == 13) {
        return push();
    }
    return false;
}

}
