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
    int width = 0, height = 0;

    for ( auto widget: subWidgets_ ) {
        widget->move(0, height);
        width = std::max(width, widget->getRect().getWidth());
        ++height;
    }
    Logger::get().log("VerticalMenu width = %i, height = %i", width, height);
    rect.resize(width, height);
    Logger::get().log("VerticalMenu layouting done");
}

}
