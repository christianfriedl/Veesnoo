#include "MenuItem.h"


namespace nv {

MenuItem::MenuItem(const std::string& text, const int x, const int y) : FocusableWidget(Rect(x, y, text.size(), 1)), text_{text} {
}

MenuItem::MenuItem(const std::string& text) : FocusableWidget(Rect(0, 0, text.size(), 1)), text_{text} {
}

void MenuItem::refresh() {
}

bool MenuItem::receiveKey(int ch) {
    if (ch == KEY_ENTER || ch == ' ') {
        return true;
    } else
        return false;
}

}
