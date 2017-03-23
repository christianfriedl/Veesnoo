#include "MenuItem.h"
#include "BasicEvent.h"


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
        cursesWindow_->attrOn(A_REVERSE);
    }

    addString(text_, 0, 0); 

    for ( int i = std::min(rect_.getWidth(), (int)text_.length()); i < rect_.getWidth(); ++i )
        addCh(fillChar, i, 0);

    if ( isFocused() )
        cursesWindow_->attrOff(A_REVERSE);

    Widget::refresh();
}

bool MenuItem::push() {
    auto ev(std::make_shared<BasicEvent>(shared_from_this()));
    onAfterPush.emit(ev);
    return true;
}

bool MenuItem::receiveKey(int ch) {
    Logger::get().log("MenuItem(%llx)::receiveKey(%i)", this, ch);
    if (ch == KEY_ENTER || ch == ' ') {
        return push();
    } else
        return false;
}

}
