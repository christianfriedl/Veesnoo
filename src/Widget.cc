// #include "ColorAttribute.h"
// #include "App.h"
#include <memory>
#include <iostream>
#include <sstream>
#include "Rect.h"
#include "CursesWindow.h"
#include "Widget.h"
#include "Logger.h"
#include "CursesException.h"

namespace nv {

Widget::Widget(const Rect& rect): rect(rect), contentRect(0, 0, rect.getWidth(), rect.getHeight()), isVisible(true), parent_(NULL) {
    Logger::get().log("new Widget @ %ld (x: %i, y: %i)", this, rect.getX(), rect.getY());

    this->cw = std::make_unique<CursesWindow>(this->getAbsoluteRect());
}

std::unique_ptr<std::string> Widget::toString() {
    std::ostringstream ostr;
    ostr << "<Widget @ " << this << " rect: " << *(rect.toString()) << std::endl;
    ostr << "    contentRect: " << *(contentRect.toString()) << std::endl;
    ostr << ">";
    return std::make_unique<std::string>(ostr.str());
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
    cw->move(getAbsoluteRect()->getX(), getAbsoluteRect()->getY());
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
Widget::setCWPosition() {
    auto absoluteRect = getAbsoluteRect(); 
    cw->move(absoluteRect->getX(), absoluteRect->getY());
}

void 
Widget::setCWSize() {
    auto absoluteRect = getAbsoluteRect();
    cw->resize(absoluteRect->getWidth(), absoluteRect->getHeight());
}

void 
Widget::refresh() {
    setCWPosition(); // not necessary until we have a working move(), but what the bloody heck
    cw->refresh();
}

void 
Widget::addString(const std::string& text) {
    Logger::get().log("Widget adding text to contentRect: %s, %i %i", text.c_str(), contentRect.getX(), contentRect.getY());
    cw->addString(text, contentRect.getX(), contentRect.getY());
}

void 
Widget::addString(const std::string& text, const int x, const int y) {
    cw->addString(text, contentRect.getX() + x, contentRect.getY() + y);
}

void 
Widget::addCh(int ch) {
    cw->addCh(ch, contentRect.getX(), contentRect.getY());
}

void 
Widget::addCh(const int ch, const int x, const int y) {
    cw->addCh(ch, contentRect.getX() + x, contentRect.getY() + y);
}

}
