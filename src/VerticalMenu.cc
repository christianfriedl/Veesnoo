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
    Logger::get().log("VerticalMenu @%llx layouting", this);
    int height = 0, i = 0, width = 0;

    for ( auto widget: subWidgets_ ) {
        ++height;
        ++i;
        widget->move(0, height);
        width = std::max(width, widget->getRect().getWidth());
    }
    Logger::get().log("VerticalMenu width is %i, i is %i", width, i);
    rect.resize(width, height);
    Logger::get().log("VerticalMenu layouting done");
}

}
