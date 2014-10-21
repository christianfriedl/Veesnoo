#include <unistd.h>
#include <ncursesw/ncurses.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Widget.h"
#// include "KeyReceiving.h"
#include "SingleFocusManager.h"
#include "Checkbox.h"

namespace nv {

Checkbox::Checkbox(const std::string& text, int x, int y): FocusableWidget(Rect(x, y, text.size() + 3, 1)), text_(text), state_(CheckboxState_unchecked) {
    focusManager_ = new SingleFocusManager(*this); 
}

void Checkbox::refresh() {
    if ( focusManager_->isFocused() )
        cw->attrOn(A_REVERSE);
    char c = (state_ == CheckboxState_checked ? 'x' : ' ');
    std::stringstream s; 
    s << "[" << c << "] " << text_;
    addString(s.str(), 0, 0);
    if ( focusManager_->isFocused() )
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
