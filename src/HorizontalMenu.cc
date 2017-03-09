#include "Logger.h"
#include "HorizontalMenu.h"
#include "ContainerFocusManager.h"

namespace nv {

HorizontalMenu::HorizontalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)) { } 

void HorizontalMenu::addWidget(const std::shared_ptr<Widget>& widget) {
    FocusableContainer::addWidget(widget);
    layout();
}

void HorizontalMenu::layout() {
    Logger::get().log("HorizontalMenu @%llx layouting", this);
    int width = 0, i = 0;

    for ( auto widget: subWidgets_ ) {
        if ( i != 0 )
            width += 1;
        ++i;
        widget->move(width, 0);
        width += widget->getRect().getWidth();
    Logger::get().log("HorizontalMenu width is %i, i is %i", width, i);
    }
    rect_.resize(width, rect_.getHeight());
    Logger::get().log("HorizontalMenu layouting done");
}

}
