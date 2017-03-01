#include "FocusableWidget.h"
#include <iostream>
#include <sstream>

namespace nv {

bool FocusableWidget::receiveKey(int ch) {
    return false;
}

void FocusableWidget::focus() {
    Logger::get().log("FocusableWidget::focus() on %s", toString().c_str());
    isFocused_ = true;
}

void FocusableWidget::deFocus() {
    Logger::get().log("FocusableWidget::deFocus() on %s", toString().c_str());
    isFocused_ = false;
}

void FocusableWidget::blur() {
    deFocus();
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
