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

Widget::Widget(): rect(0, 0, 1, 1), contentRect(0, 0, 1, 1), isVisible(false), parent_(std::weak_ptr<Widget>()) {}

// constructor: set parent_ to "null", size from rect and make visible by default
Widget::Widget(const Rect& rect): rect(rect), contentRect(0, 0, rect.getWidth(), rect.getHeight()), isVisible(true), parent_(std::weak_ptr<Widget>()) {
    Logger::get().log("new Widget %s", toString().c_str());

    cw = std::make_unique<CursesWindow>(this->getAbsoluteRect());
}

// it seems we don't need special cons' after all
/*
Widget::Widget(Widget&& other) : cw(nullptr), rect(0, 0, 0, 0), contentRect(0, 0, 0, 0), parent_(std::weak_ptr<Widget>()) {
    std::swap(cw, other.cw);
    std::swap(rect, other.rect);
    std::swap(contentRect, other.contentRect);
    std::swap(parent_, other.parent_);
}

Widget& Widget::operator=(Widget&& other) {
    rect = Rect(0, 0, 0, 0);
    contentRect = Rect(0, 0, 0, 0);
    parent_ = nullptr;
    cw = nullptr;

    std::swap(cw, other.cw);
    std::swap(rect, other.rect);
    std::swap(contentRect, other.contentRect);
    std::swap(parent_, other.parent_);

    return *this;
}
*/

const std::string Widget::toString() const {
    std::ostringstream ostr;
    ostr << "<Widget @ " << (unsigned long long int)this << " rect: " << *(rect.toString()) << std::endl;
    ostr << "    contentRect: " << *(contentRect.toString()) << std::endl;
    ostr << "    absoluteRect: " << *(getAbsoluteRect().toString()) << std::endl;
    ostr << "    absoluteContentRect: " << *(getAbsoluteContentRect().toString()) << std::endl;
    ostr << ">";
    return ostr.str();
}

void 
Widget::resize(const int width, const int height) {
    rect.resize(width, height);
    cw->resize(width, height);
}

void 
Widget::move(const int x, const int y) {
    rect.move(x, y);
    cw->move(getAbsoluteRect().getX(), getAbsoluteRect().getY());
}

const std::weak_ptr<Widget>&
Widget::getParent() const {
    return parent_;
}

bool 
Widget::getIsVisible() const {
    return isVisible;
}

void
Widget::setParent(const std::weak_ptr<Widget>& parent) {
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
    if ( parent_.use_count() != 0 ) {
        if ( auto parent = parent_.lock() ) {
            const Rect parentAbsoluteRect = parent->getAbsoluteRect();
            return Rect(parentAbsoluteRect.getX() + rect.getX(), parentAbsoluteRect.getY() + rect.getY(), rect.getWidth(), rect.getHeight());
        }
    } else {
        const Rect parentAbsoluteRect(0, 0, 1, 1);
        return Rect(parentAbsoluteRect.getX() + rect.getX(), parentAbsoluteRect.getY() + rect.getY(), rect.getWidth(), rect.getHeight());
    }
}

Rect 
Widget::getAbsoluteContentRect() const {
    if ( parent_.use_count() != 0 ) {
        if ( auto parent = parent_.lock() ) {
            const Rect parentAbsoluteContentRect = parent->getAbsoluteContentRect();
            return Rect(parentAbsoluteContentRect.getX() + rect.getX() + contentRect.getX(), parentAbsoluteContentRect.getY() + rect.getY() + contentRect.getY(), rect.getWidth(), contentRect.getHeight());
        } else
            throw std::runtime_error("parent should be there, but was not lockable");
    } else {
        const Rect parentAbsoluteContentRect(0, 0, 1, 1);
        return Rect(parentAbsoluteContentRect.getX() + rect.getX() + contentRect.getX(), parentAbsoluteContentRect.getY() + rect.getY() + contentRect.getY(), rect.getWidth(), contentRect.getHeight());
    }
}

void 
Widget::setCWPosition() {
    auto absoluteRect = getAbsoluteRect(); 
    cw->move(absoluteRect.getX(), absoluteRect.getY());
}

void 
Widget::setCWSize() {
    auto absoluteRect = getAbsoluteRect();
    cw->resize(absoluteRect.getWidth(), absoluteRect.getHeight());
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
    Logger::get().log("Widget adding text to contentRect: %s, %i %i, @ x %i y %i", text.c_str(), contentRect.getX(), contentRect.getY(), x, y);
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
