#include "Window.h"

namespace nv {

Window::Window(const Rect& rect) : FocusableContainer(rect) {
    const Rect& parentAbsoluteContentRect = parent_ ? parent_->getAbsoluteContentRect() : Rect(0, 0, 1, 1);
    absoluteRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX(), parentAbsoluteContentRect.getY() + rect.getY(),
            rect.getWidth(), rect.getHeight());
    absoluteContentRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX() + 1, parentAbsoluteContentRect.getY() + rect.getY() + 1,
            rect.getWidth() - 2, rect.getHeight() - 2);
    setCWPosition();
}

}
