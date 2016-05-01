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

// constructor: set parent_ to "null", size from rect and make visible by default
Widget::Widget(const Rect& rect): rect(rect), contentRect(0, 0, rect.getWidth(), rect.getHeight()), isVisible(true), parent_(std::weak_ptr<Widget>()) {
    Logger::get().log("new Widget @ %lld (x: %i, y: %i)", this, rect.getX(), rect.getY());

    cw = std::make_unique<CursesWindow>(this->getAbsoluteRect());
}

// it seems we don't need special cons' after all
/*
    std::swap(rect, other.rect);
    std::swap(contentRect, other.contentRect);
    std::swap(parent_, other.parent_);
}

Widget& Widget::operator=(Widget&& other) {
    rect = Rect(0, 0, 0, 0);
    contentRect = Rect(0, 0, 0, 0);
    parent_ = nullptr;

    std::swap(rect, other.rect);
    std::swap(contentRect, other.contentRect);
    std::swap(parent_, other.parent_);

    return *this;
}
*/

std::unique_ptr<const std::string> Widget::toString() const {
    std::ostringstream ostr;
    ostr << "<Widget @ " << this << " rect: " << *(rect.toString()) << std::endl;
    ostr << "    contentRect: " << *(contentRect.toString()) << std::endl;
    ostr << "    absoluteRect: " << *(getAbsoluteRect().toString()) << std::endl;
    ostr << "    absoluteContentRect: " << *(getAbsoluteContentRect().toString()) << std::endl;
    ostr << ">";
    return std::make_unique<std::string>(ostr.str());
}

void 
Widget::resize(const int width, const int height) {
    rect.resize(width, height);
}

void 
Widget::move(const int x, const int y) {
    rect.move(x, y);
    contentRect.move(x, y);
}

std::weak_ptr<Widget>
Widget::getParent() const {
    return parent_;
}

bool 
Widget::getIsVisible() const {
    return isVisible;
}

void
Widget::setParent(const std::weak_ptr<Widget> parent) {
    parent_ = parent;
}


Rect
Widget::getRect() const {
    return rect;
}

Rect
Widget::getContentRect() const {
    return contentRect;
}

Rect 
Widget::getAbsoluteRect() const {
    auto sharedParent = parent_.lock();
    if ( sharedParent ) {
        const Rect parentAbsoluteRect = sharedParent.get() ? sharedParent.get()->getAbsoluteRect() : Rect(0, 0, 1, 1);
        return Rect(parentAbsoluteRect.getX() + rect.getX(), parentAbsoluteRect.getY() + rect.getY(), rect.getWidth(), rect.getHeight());
    } else {
        const Rect parentAbsoluteRect(0, 0, 1, 1);
        return Rect(parentAbsoluteRect.getX() + rect.getX(), parentAbsoluteRect.getY() + rect.getY(), rect.getWidth(), rect.getHeight());
    }
}

Rect 
Widget::getAbsoluteContentRect() const {
    auto sharedParent = parent_.lock();
    if ( sharedParent ) {
        const Rect parentAbsoluteContentRect = sharedParent.get() ? sharedParent.get()->getAbsoluteContentRect() : Rect(0, 0, 1, 1);
        return Rect(parentAbsoluteContentRect.getX() + rect.getX() + contentRect.getX(), parentAbsoluteContentRect.getY() + rect.getY() + contentRect.getY(), rect.getWidth(), contentRect.getHeight());
    } else {
        const Rect parentAbsoluteContentRect(0, 0, 1, 1);
        return Rect(parentAbsoluteContentRect.getX() + rect.getX() + contentRect.getX(), parentAbsoluteContentRect.getY() + rect.getY() + contentRect.getY(), rect.getWidth(), contentRect.getHeight());
    }
}

void 
Widget::setCWPosition() {
    auto absoluteRect = getAbsoluteRect(); 
}

void 
Widget::setCWSize() {
    auto absoluteRect = getAbsoluteRect();
}

void 
Widget::refresh() {
    setCWPosition(); // not necessary until we have a working move(), but what the bloody heck
}

void 
Widget::addString(const std::string& text) {
    Logger::get().log("Widget adding text to contentRect: %s, %i %i", text.c_str(), contentRect.getX(), contentRect.getY());
}

void 
Widget::addString(const std::string& text, const int x, const int y) {
}

void 
Widget::addCh(int ch) {
}

void 
Widget::addCh(const int ch, const int x, const int y) {
}

}
