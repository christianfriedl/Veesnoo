#include <unistd.h>
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
        LOGMETHODONLY();
        if ( !getIsVisibleBubbling() )
            return;
        if ( isFocused() || state_ == ButtonState_pushed)
            cursesWindow_->attrOn(A_REVERSE);
        std::stringstream s; 
        s << "[ " << text_ << " ]";
        addString(s.str(), 0, 0);
        if ( isFocused() || state_ == ButtonState_pushed)
            cursesWindow_->attrOff(A_REVERSE);
        FocusableWidget::refresh();
    }

    bool Button::push() {
        Logger::get().log("Button(%llx)::push()", this);
        state_ = ButtonState_pushed;
        // TODO do stuff
        refresh();
        state_ = ButtonState_normal;
        refresh();
        auto ev(std::make_shared<BasicEvent>(shared_from_this()));
        onAfterPush.emit(ev);
        return true;
    }

    bool Button::receiveKey(int ch) {
        LOGMETHOD("%i", ch);
        if (ch == ' ' || ch == 13) {
            return push();
        }
        return false;
    }

}

