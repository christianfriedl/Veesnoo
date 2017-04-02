#include "Label.h"

namespace nv {

    void Label::setText(const std::string& text) {
        text_ = text;
        resize(text_.length(), 1);
    }
    void Label::refresh() {
        Logger::get().log("Label(%lld)::refresh()", this);
        if ( !getIsVisibleBubbling() )
            return;
        addString(text_, 0, 0);
        Widget::refresh();
    }

}
