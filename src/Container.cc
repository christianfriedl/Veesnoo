#include "Container.h"

namespace nv {

void 
Container::addWidget(std::shared_ptr<Widget> widget) {
    widget->setParent(std::shared_ptr<Widget>(this));
    subWidgets_.push_back(widget);
}

void Container::refresh() {
    Widget::refresh();
    for ( auto widget: subWidgets_)
        widget.get()->refresh();
}

}
