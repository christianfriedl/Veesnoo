// #include "ColorAttribute.h"
// #include "App.h"
#include <tr1/memory>
#include "Rect.h"
#include "CursesWindow.h"
#include "Widget.h"
#include "CursesException.h"

namespace nv {

Widget::Widget(const Rect& rect): isVisible(true), parent(NULL) {
    this->rect = new Rect(rect);
    this->contentRect = new Rect(rect);

    const Rect& parentAbsoluteContentRect = getParentAbsoluteContentRect();
    absoluteRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX(), parentAbsoluteContentRect.getY() + rect.getY(),
            rect.getWidth(), rect.getHeight());
    absoluteContentRect = new Rect(parentAbsoluteContentRect.getX() + rect.getX(), parentAbsoluteContentRect.getY() + rect.getY(),
            rect.getWidth(), rect.getHeight());

    this->cw = new CursesWindow(*absoluteRect);

    /*
    App *app = [App sharedInstance];

    self.contentColAttr = [app contentColAttr];
    self.borderColAttr = [app borderColAttr];
    self.focusedColAttr = [app focusedColAttr];
    self.focusedBorderColAttr = [app focusedBorderColAttr];
    self.activeColAttr = [app activeColAttr];
    */
}

Widget::~Widget() {
    delete cw;
    delete contentRect;
    delete rect;
}

void Widget::resize(const int width, const int height) {
    throw CursesException("not yet implemented");
    cw->resize(width, height);
    rect->resize(width, height);
    contentRect->resize(width, height);
}

void Widget::move(const int x, const int y) {
    throw CursesException("not yet implemented");
    cw->move(x, y);
    rect->move(x, y);
    contentRect->move(x, y);
}

const Rect& Widget::getParentAbsoluteContentRect() const {
    if (parent == NULL)
        return *contentRect;
    else
        return parent->getAbsoluteContentRect();
}

void Widget::recalculateAbsoluteRects() {
    const Rect& parentAbsoluteContentRect = getParentAbsoluteContentRect();
    absoluteRect->move(parentAbsoluteContentRect.getX() + absoluteRect->getX(), parentAbsoluteContentRect.getY() + absoluteRect->getY());
    absoluteContentRect->move(parentAbsoluteContentRect.getX() + absoluteContentRect->getX(), parentAbsoluteContentRect.getY() + absoluteContentRect->getY());
}

const Rect& Widget::getAbsoluteRect() const {
    return *absoluteRect;
}

const Rect& Widget::getAbsoluteContentRect() const {
    return *absoluteContentRect;
}

void Widget::setCWPosition() {
    cw->move(absoluteRect->getX(), absoluteRect->getY());
}

void Widget::setCWSize() {
    cw->resize(absoluteRect->getWidth(), absoluteRect->getHeight());
}

void Widget::refresh() {
    setCWPosition(); // not necessary until we have a working move(), but what the bloody heck
    cw->refresh();
}

void Widget::addString(const std::string& text) {
    cw->addString(text);
}

void Widget::addString(const std::string& text, const int x, const int y) {
    cw->addString(text, x, y);
}
void Widget::addCh(int ch) {
    cw->addCh(ch);
}
void Widget::addCh(const int ch, const int x, const int y) {
    cw->addCh(ch, x, y);
}

}
