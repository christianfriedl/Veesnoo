#include "Label.h"

namespace nv {

void Label::refresh() {
    addString(text_, 0, 0);
    Widget::refresh();
}

}
