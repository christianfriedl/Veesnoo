#include "MenuItem.h"


namespace nv {

MenuItem::MenuItem(const std::string& text, const int x, const int y) : FocusableWidget(Rect(x, y, text.size(), 1)), text_{text} {
}

MenuItem::MenuItem(const std::string& text) : FocusableWidget(Rect(0, 0, text.size(), 1)), text_{text} {
}

void MenuItem::refresh() {
    Logger::get().log("MenuItem::refresh(), text: '%s', %s, isFocused=%i", text_.c_str(), toString().c_str(), isFocused());

    char fillChar = ' ';
    if ( isFocused() ) {
        Logger::get().log("is focused! ");
        cw->attrOn(A_REVERSE);
    }

    addString(text_, 0, 0); 

    for ( int i = std::min(rect.getWidth(), (int)text_.length()); i < rect.getWidth(); ++i )
        addCh(fillChar, i, 0);

    if ( isFocused() )
        cw->attrOff(A_REVERSE);
}

bool MenuItem::receiveKey(int ch) {
    if (ch == KEY_ENTER || ch == ' ') {
        return true;
    } else
        return false;
}

}
