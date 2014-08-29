// #include "ColorAttribute.h"
// #include "App.h"
#include <tr1/memory>
#include "Rect.h"
#include "Widget.h"
#include "CursesWindow.h"
#include "CursesException.h"

namespace nv {

Widget::Widget(const Rect& rect): isVisible(true), parent(NULL) {
    this->rect = new Rect(rect);
    this->contentRect = new Rect(rect);
    this->cw = new CursesWindow(rect);

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

const Rect *Widget::getAbsoluteContentRect() const {
    if (parent == NULL)
        return new Rect(*contentRect);
    Rect *acr = new Rect(*(parent->getAbsoluteContentRect()));
    acr->move(acr->getX() + contentRect->getX(), acr->getY() + contentRect->getY());
    acr->resize(contentRect->getWidth(), contentRect->getHeight());
    return acr;
}

const Rect *Widget::getAbsoluteRect() const {
    if (parent == NULL)
        return new Rect(*contentRect);
    Rect *ar = new Rect(*(parent->getAbsoluteContentRect()));
    ar->move(ar->getX() + rect->getX(), ar->getY() + rect->getY());
    ar->resize(rect->getWidth(), rect->getHeight());
    return ar;
}

void Widget::setCWPosition() {
    const Rect *ar = getAbsoluteRect();
    cw->move(ar->getX(), ar->getY());
    delete ar;
}

void Widget::setCWSize() {
    const Rect *ar = getAbsoluteRect();
    cw->resize(ar->getWidth(), ar->getHeight());
    delete ar;
}

void Widget::refresh() {
    setCWPosition();
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
