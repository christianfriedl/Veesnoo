// #include "ColorAttribute.h"
// #include "App.h"
#include <memory>
#include "Rect.h"
#include "CursesWindow.h"
#include "Widget.h"
#include "Logger.h"
#include "CursesException.h"

namespace nv {

Widget::Widget(const Rect& rect): rect(rect), contentRect(rect), isVisible(true), parent_(NULL) {
    Logger::get().log("new Widget @ %ld (x: %i, y: %i)", this, rect.getX(), rect.getY());

    /*
    absoluteRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX(), parentAbsoluteContentRect.getY() + rect.getY(),
            rect.getWidth(), rect.getHeight());
    absoluteContentRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX(), parentAbsoluteContentRect.getY() + rect.getY(),
            rect.getWidth(), rect.getHeight());
            */

    this->cw = std::make_unique<CursesWindow>(this->getAbsoluteRect());
}

void 
Widget::resize(const int width, const int height) {
    rect.resize(width, height);
    cw->resize(width, height);
}

void 
Widget::move(const int x, const int y) {
    rect.move(x, y);
    contentRect.move(x, y);
    cw->move(getAbsoluteRect().getX(), getAbsoluteRect().getY());
}

std::unique_ptr<const Rect> 
Widget::getAbsoluteRect() const {
    const Rect& parentAbsoluteRect = parent_ ? *(parent_->getAbsoluteRect().get()) : Rect(0, 0, 1, 1);
    return std::make_unique<const Rect>(parentAbsoluteRect.getX() + rect.getX(), parentAbsoluteRect.getY() + rect.getY(), rect.getWidth(), rect.getHeight());
}

std::unique_ptr<const Rect> 
Widget::getAbsoluteContentRect() const {
    const Rect& parentAbsoluteContentRect = parent_ ? *(parent_->getAbsoluteContentRect().get()) : Rect(0, 0, 1, 1);
    return std::make_unique<const Rect>(parentAbsoluteContentRect.getX() + contentRect.getX(), parentAbsoluteContentRect.getY() + contentRect.getY(), rect.getWidth(), contentRect.getHeight());
}

void
Widget::calculateContentRect() {
    contentRect->move(0, 0);
    contentRect->resize(rect->getWidth(), rect->getHeight());
}

void 
Widget::calculateRects() {
    Logger::get().log("Widget::calculateRects was called");
    calculateContentRect();
    calculateAbsoluteRects();
}

inline
const Rect& 
Widget::getAbsoluteContentRect() const {
    return *absoluteContentRect;
}

void 
Widget::setCWPosition() {
    cw->move(absoluteRect->getX(), absoluteRect->getY());
}

void 
Widget::setCWSize() {
    cw->resize(absoluteRect->getWidth(), absoluteRect->getHeight());
}

void 
Widget::refresh() {
    setCWPosition(); // not necessary until we have a working move(), but what the bloody heck
    cw->refresh();
}

void 
Widget::addString(const std::string& text) {
    cw->addString(text, contentRect->getX(), contentRect->getY());
}

void 
Widget::addString(const std::string& text, const int x, const int y) {
    cw->addString(text, contentRect->getX() + x, contentRect->getY() + y);
}

void 
Widget::addCh(int ch) {
    cw->addCh(ch, contentRect->getX(), contentRect->getY());
}

void 
Widget::addCh(const int ch, const int x, const int y) {
    cw->addCh(ch, contentRect->getX() + x, contentRect->getY() + y);
}

}
