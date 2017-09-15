#include "Label.h"

namespace nv {

    Label::Label(const std::string& text, const int x, const int y): Widget(Rect(x, y, text.size(), 1)), text_(text) { 
        LOGMETHOD("%s %s", toString().c_str(), text_.c_str()); 
    }

    void Label::setText(const std::string& text) {
        text_ = text;
        resize(text_.length(), 1);
    }
    void Label::refresh() {
        LOGMETHODONLY();
        if ( !getIsVisibleBubbling() )
            return;
        addString(text_, 0, 0);
        Widget::refresh();
    }

}
