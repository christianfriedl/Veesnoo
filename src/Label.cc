#include "Label.h"

namespace nv {

    Label::Label(const std::string& text, const int x, const int y): Widget(Rect(x, y, text.size(), 1)), text_(text) { 
        LOGMETHOD("%s %s", toString().c_str(), text_.c_str()); 
        primaryColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_YELLOW, COLOR_BLUE);
    }

    void Label::setText(const std::string& text) {
        text_ = text;
        resize(text_.length(), 1);
    }
    void Label::addContent() {
        LOGMETHODONLY();
        addString(text_, 0, 0);
    }

}
