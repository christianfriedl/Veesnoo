#include "Logger.h"
#include "VerticalMenu.h"
#include "ContainerFocusManager.h"

namespace nv {

VerticalMenu::VerticalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)), addedItems_() {
    Logger::get().log("new VerticalMenu @ %ld (x: %i, y: %i)", this, x, y);
    focusManager_ = new ContainerFocusManager(*this); 
}

VerticalMenu::~VerticalMenu() {
    addedItems_.clear();
}

void VerticalMenu::pack() {
    std::vector<Widget *>::iterator iter;

    unsigned int width = 0, height = 0;

    for ( iter = subWidgets_.begin(); iter != subWidgets_.end(); ++iter, ++height ) {
        (*iter)->move(0, height);
        if ( (*iter)->getRect().getWidth() > width )
            width = (*iter)->getRect().getWidth();
    }
    rect->resize(width, height);
}

MenuItem& VerticalMenu::addItem(const std::string& name) {
    MenuItem *item = new MenuItem(name);
    FocusableContainer::addWidget(*item);
    addedItems_.push_back(item);
    return *item;
}

}
