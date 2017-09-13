#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include <string.h>
#include "Widget.h"
#include "RadioButton.h"

namespace nv {

    RadioButton::RadioButton(int x, int y, const std::string& value): FocusableWidget(Rect(x, y, 3, 1)), state_(RadioButtonState::unchecked), frame_("{}"), value_(value) {
    }

    void RadioButton::setFrame(const std::string& frame) {
        frame_ = frame;
    }

    void RadioButton::setChecked(const bool checked) {
        if ( checked )
            state_ = RadioButtonState::checked;
        else
            state_ = RadioButtonState::unchecked;
    }

    void RadioButton::refresh() {
        LOGMETHODONLY();
        if ( !getIsVisibleBubbling() )
            return;
        if ( isFocused() )
            cursesWindow_->attrOn(A_REVERSE);
        char c = (state_ == RadioButtonState::checked ? '+' : ' ');
        std::stringstream s; 
        s << frame_[0] << c << frame_[1];
        addString(s.str(), 0, 0);
        if ( isFocused() )
            cursesWindow_->attrOff(A_REVERSE);
        FocusableWidget::refresh();
    }

    bool RadioButton::push() {
        state_ = (state_ == RadioButtonState::checked ? RadioButtonState::unchecked : RadioButtonState::checked);
        {
            auto ev(std::make_shared<ChangeEvent>(shared_from_this()));
            onAfterChange.emit(ev);
        }
        refresh();
        return true;
    }

    bool RadioButton::isChecked() {
        return state_ == RadioButtonState::checked;
    }

    bool RadioButton::receiveKey(int ch) {
        LOGMETHOD("%i", ch);
        if (ch == ' ' || ch == 13) {
            return push();
        }
        return false;
    }

}
