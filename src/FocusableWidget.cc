#include "FocusableWidget.h"
#include "FocusableContainer.h"
#include <iostream>
#include <sstream>

namespace nv {

#pragma clang diagnostic ignored "-Wunused-parameter"
bool FocusableWidget::receiveKey(int ch) {
    return false;
}

void FocusableWidget::focus() {
    Logger::get().log("FocusableWidget::focus() on %s", toString().c_str());
    isFocused_ = true;
    auto p = parent_.lock();
    if ( p ) {
        auto p2 = std::dynamic_pointer_cast<FocusableContainer>(p);
        if ( !p2 )
            throw Exception("cannot cast parent to FocusableContainer");
        std::shared_ptr<Focusable> this2 = std::dynamic_pointer_cast<Focusable>(shared_from_this());
        if ( !this2 )
            throw Exception("cannot cast this to Focusable");
        p2->subWidgetHasFocused(this2);
    }
}

void FocusableWidget::blur() {
    Logger::get().log("FocusableWidget::blur() on %s", toString().c_str());
    isFocused_ = false;
}

bool FocusableWidget::isFocused() const {
    return isFocused_;
}

const std::string FocusableWidget::toString() const {
    std::ostringstream ostr;
    ostr << "<FocusableWidget " << Widget::toString();
    ostr << "isFocused=" << isFocused_ << ">";
    return ostr.str();
}


}
