#include "Container.h"

namespace nv {

static void setToChild(Container *parent, const std::shared_ptr<Widget>& child) {
    auto x = std::shared_ptr<Container>(parent);
    child->setParent(parent->shared_from_this());
}

void 
Container::addWidget(const std::shared_ptr<Widget>& widget) {
    setToChild(this, widget);
    subWidgets_.emplace_back(widget);
}

void Container::refresh() {
    Widget::refresh();
    for ( auto widget: subWidgets_)
        widget.get()->refresh();
}

}
