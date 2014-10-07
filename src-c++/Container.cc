#include "Container.h"

namespace nv {

void Container::addWidget(Widget& widget) {
    widget.setParent(*this);
    subWidgets_.push_back(&widget);
}

}
