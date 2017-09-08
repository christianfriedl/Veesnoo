#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include <string.h>
#include "Widget.h"
#include "CheckBox.h"

namespace nv {

    CheckBox::CheckBox(int x, int y): FocusableWidget(Rect(x, y, 3, 1)), state_(CheckboxState_unchecked), frame_("[]") {
    }

    void CheckBox::setFrame(const std::string& frame) {
        frame_ = frame;
    }

    void CheckBox::refresh() {
        Logger::get().log("CheckBox(%llx)::refresh()", this);
        if ( !getIsVisibleBubbling() )
            return;
        if ( isFocused() )
            cursesWindow_->attrOn(A_REVERSE);
        char c = (state_ == CheckboxState_checked ? 'x' : ' ');
        std::stringstream s; 
        s << frame_[0] << c << frame_[1];
        addString(s.str(), 0, 0);
        if ( isFocused() )
            cursesWindow_->attrOff(A_REVERSE);
        FocusableWidget::refresh();
    }

    bool CheckBox::push() {
        state_ = (state_ == CheckboxState_checked ? CheckboxState_unchecked : CheckboxState_checked);
        // TODO do stuff
        refresh();
        return true;
    }

    bool CheckBox::isChecked() {
        return state_ == CheckboxState_checked;
    }

    bool CheckBox::receiveKey(int ch) {
        if (ch == ' ' || ch == 13) {
            return push();
        }
        return false;
    }

}
