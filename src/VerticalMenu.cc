#include "Logger.h"
#include "VerticalMenu.h"
#include "ContainerFocusManager.h"

namespace nv {

VerticalMenu::VerticalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)) { } 

void VerticalMenu::addWidget(const std::shared_ptr<Widget>& widget) {
    FocusableContainer::addWidget(widget);
    layout();
}

void VerticalMenu::layout() {
    int width = 0, height = 0;

    for ( auto widget: subWidgets_ ) {
        widget->move(0, height);
        width = std::max(width, widget->getRect().getWidth());
        ++height;
    }
    rect.resize(width, height);
}

}
