#include "Container.h"

namespace nv {

void 
Container::addWidget(Widget& widget) {
    widget.setParent(*this);
    subWidgets_.push_back(&widget);
}

void Container::refresh() {
    Widget::refresh();
    for ( std::vector<Widget*>::iterator iter = subWidgets_.begin();
            iter != subWidgets_.end(); ++iter )
        (*iter)->refresh();
}

}
