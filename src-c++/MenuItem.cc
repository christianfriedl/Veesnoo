#include "MenuItem.h"


namespace nv {

MenuItem::MenuItem(const std::string& text, const int x, const int y) : FocusableWidget(Rect(x, y, text.size(), 1), *(new SingleFocusManager(*this))), text_(text) {
    focusManager_->setWidget(*this);
}

MenuItem::MenuItem(const std::string& text) : FocusableWidget(Rect(0, 0, text.size(), 1), *(new SingleFocusManager(*this))), text_(text) {
    focusManager_->setWidget(*this);
}

void MenuItem::refresh() {
    if (isFocused())
        cw->attrOn(A_REVERSE);
    addString(text_, 0, 0);
    if (isFocused())
        cw->attrOff(A_REVERSE);
    FocusableWidget::refresh();
}

bool MenuItem::receiveKey(int ch) {
    if (ch == KEY_ENTER || ch == ' ') {
        return true;
    } else
        return false;
}

}
