#include "ContainerFocusManager.h"
#include "Window.h"

namespace nv {

Window::Window(const Rect& rect, const std::string title) : FocusableContainer(rect), title_(title) {
    focusManager_ = new ContainerFocusManager(*this);
    const Rect& parentAbsoluteContentRect = parent_ ? parent_->getAbsoluteContentRect() : Rect(0, 0, 1, 1);
    absoluteRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX(), parentAbsoluteContentRect.getY() + rect.getY(),
            rect.getWidth(), rect.getHeight());
    absoluteContentRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX() + 1, parentAbsoluteContentRect.getY() + rect.getY() + 1,
            rect.getWidth() - 2, rect.getHeight() - 2);
    setCWPosition();
}

void
Window::calculateContentRect() {
    contentRect->move(1, 1);
    contentRect->resize(rect->getWidth() - 2, rect->getHeight() - 2);
}

void
Window::resize(const int width, const int height) {
    FocusableContainer::resize(width, height);
    calculateRects();
}

void 
Window::refresh() {
    setCWPosition(); // not necessary until we have a working move(), but what the bloody heck
    cw->addBorder();
    cw->addString(title_, ( rect->getWidth() - title_.size() ) / 2, 0);
    FocusableContainer::refresh();
}


}
