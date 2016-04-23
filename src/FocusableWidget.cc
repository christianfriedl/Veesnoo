#include "FocusableWidget.h"

namespace nv {

bool FocusableWidget::receiveKey(int ch) {
    return false;
}

void FocusableWidget::focus() {
    isFocused_ = true;
}

void FocusableWidget::deFocus() {
    isFocused_ = false;
}

}
