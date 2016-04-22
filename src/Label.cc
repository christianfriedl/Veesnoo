#include "Label.h"

namespace nv {

/*
Label::Label(Label&& other): Widget() {
    std::swap(*this, other);
}

Label& Label::operator=(Label&& other) {
    Widget::Widget::operator=(other);
    std::swap(text_, other.text_);

    return *this;
}
*/

void Label::refresh() {
    addString(text_, 0, 0);
    Widget::refresh();
}

}
