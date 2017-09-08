#include "NVBase.h"
#include "MenuItem.h"
#include "BasicEvent.h"


namespace nv {

MenuItem::MenuItem(const std::string& text, const int x, const int y) : FocusableWidget(Rect(x, y, text.size(), 1)), text_{text} {
    Logger::get().log("MenuItem::MenuItem(%s, %i, %i)", text.c_str(), x, y);
}

MenuItem::MenuItem(const std::string& text) : FocusableWidget(Rect(0, 0, text.size(), 1)), text_{text} {
    Logger::get().log("MenuItem::MenuItem(%s)", text.c_str());
}

void MenuItem::refresh() {
    Logger::get().log("MenuItem(%llx)::refresh(), text: '%s', %s, isFocused=%i", this, text_.c_str(), toString().c_str(), isFocused());
    if ( !getIsVisibleBubbling() )
        return;

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
    LOGMETHOD(ch);
    if (ch == Key_Enter || ch == ' ') {
        return push();
    } else
        return false;
}

const std::string& MenuItem::getText() {
    return text_;
}

}
