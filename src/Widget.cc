// #include "ColorAttribute.h"
// #include "App.h"
#include <tr1/memory>
#include "Rect.h"
#include "CursesWindow.h"
#include "Widget.h"
#include "CursesException.h"

namespace nv {

Widget::Widget(const Rect& rect): isVisible(true), parent_(NULL) {
    this->rect = new Rect(rect);
    this->contentRect = new Rect(0, 0, rect.getWidth(), rect.getHeight());

    const Rect& parentAbsoluteContentRect = parent_ ? parent_->getAbsoluteContentRect() : Rect(0, 0, 1, 1);
    absoluteRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX(), parentAbsoluteContentRect.getY() + rect.getY(),
            rect.getWidth(), rect.getHeight());
    absoluteContentRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX(), parentAbsoluteContentRect.getY() + rect.getY(),
            rect.getWidth(), rect.getHeight());

    this->cw = new CursesWindow(*absoluteRect);
}

Widget::~Widget() {
    delete cw;
    delete contentRect;
    delete rect;
}

void 
Widget::resize(const int width, const int height) {
    throw CursesException("not yet implemented");
    cw->resize(width, height);
    rect->resize(width, height);
    contentRect->resize(width, height);
}

void 
Widget::move(const int x, const int y) {
    rect->move(x, y);
    contentRect->move(x, y);
    calculateRects();
    cw->move(absoluteRect->getX(), absoluteRect->getY());
}

void 
Widget::calculateAbsoluteRects() {
    const Rect& parentAbsoluteContentRect = parent_ ? parent_->getAbsoluteContentRect() : Rect(0, 0, 1, 1);
    absoluteRect->move(parentAbsoluteContentRect.getX() + rect->getX(), parentAbsoluteContentRect.getY() + rect->getY());
    absoluteContentRect->move(parentAbsoluteContentRect.getX() + contentRect->getX(), parentAbsoluteContentRect.getY() + contentRect->getY());
}

void
Widget::calculateContentRect() {
    Rect *temp = contentRect;
    contentRect = new Rect(0, 0, rect->getWidth(), rect->getHeight());
    delete temp;
}

void 
Widget::calculateRects() {
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
