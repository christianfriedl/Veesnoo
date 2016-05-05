#include "Container.h"

namespace nv {

void 
Container::addWidget(const std::shared_ptr<Widget>& widget) {
    widget->setParent(this);
    subWidgets_.emplace_back(widget);
}

void Container::refresh() {
    Widget::refresh();
    for ( auto widget: subWidgets_)
        widget.get()->refresh();
}

}
