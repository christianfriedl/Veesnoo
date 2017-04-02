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

Widget::Widget(): rect_(0, 0, 1, 1), contentRect_(0, 0, 1, 1), isVisible_(false), parent_(std::weak_ptr<Widget>()) {}

std::shared_ptr<Widget> 
Widget::create(const Rect& rect) {
    return std::make_shared<Widget>(rect);
}

// constructor: set parent_ to "null", size from rect and make visible by default
Widget::Widget(const Rect& rect): rect_(rect), contentRect_(0, 0, rect.getWidth(), rect.getHeight()), isVisible_(true), parent_(std::weak_ptr<Widget>()) {
    Logger::get().log("new Widget %s", toString().c_str());

    cursesWindow_ = std::make_unique<CursesWindow>(this->getAbsoluteRect());
}

// it seems we don't need special cons' after all
/*
Widget::Widget(Widget&& other) : cw(nullptr), rect(0, 0, 0, 0), contentRect_(0, 0, 0, 0), parent_(std::weak_ptr<Widget>()) {
    std::swap(cw, other.cw);
    std::swap(rect, other.rect);
    std::swap(contentRect_, other.contentRect_);
    std::swap(parent_, other.parent_);
}

Widget& Widget::operator=(Widget&& other) {
    rect = Rect(0, 0, 0, 0);
    contentRect_ = Rect(0, 0, 0, 0);
    parent_ = nullptr;
    cw = nullptr;

    std::swap(cw, other.cw);
    std::swap(rect, other.rect);
    std::swap(contentRect_, other.contentRect_);
    std::swap(parent_, other.parent_);

    return *this;
}
*/

const std::string Widget::toString() const {
    std::ostringstream ostr;
    ostr << "<Widget @ " << std::hex << (unsigned long long int)this << std::dec << " rect: " << *(rect_.toString()) << std::endl;
    ostr << "    contentRect_: " << *(contentRect_.toString()) << std::endl;
    ostr << "    absoluteRect: " << *(getAbsoluteRect().toString()) << std::endl;
    ostr << "    absoluteContentRect: " << *(getAbsoluteContentRect().toString()) << std::endl;
    ostr << ">";
    return ostr.str();
}

void 
Widget::resize(const int width, const int height) {
    Logger::get().log("Widget(%lld)::resize(%i, %i)", this, width, height);
    rect_.resize(width, height);
    contentRect_.resize(width, height);
    cursesWindow_->resize(width, height);
}

void 
Widget::move(const int x, const int y) {
    rect_.move(x, y);
    cursesWindow_->move(getAbsoluteRect().getX(), getAbsoluteRect().getY());
}

const std::weak_ptr<Widget>&
Widget::getParent() const {
    return parent_;
}

bool 
Widget::getIsVisible() const {
    return isVisible_;
}

void
Widget::setParent(const std::weak_ptr<Widget>& parent) {
    parent_ = parent;
}


Rect
Widget::getRect() const {
    return rect_;
}

Rect
Widget::getContentRect() const {
    return contentRect_;
}

Rect 
Widget::getAbsoluteRect() const {
    if ( parent_.use_count() != 0 ) {
        if ( auto parent = parent_.lock() ) {
            const Rect parentAbsoluteRect = parent->getAbsoluteContentRect();
            return Rect(parentAbsoluteRect.getX() + rect_.getX(), parentAbsoluteRect.getY() + rect_.getY(), rect_.getWidth(), rect_.getHeight());
        } else
            throw Exception("parent found, but unable to obtain lock");
    } else {
        const Rect parentAbsoluteRect(0, 0, 1, 1);
        return Rect(parentAbsoluteRect.getX() + rect_.getX(), parentAbsoluteRect.getY() + rect_.getY(), rect_.getWidth(), rect_.getHeight());
    }
}

Rect 
Widget::getAbsoluteContentRect() const {
    if ( parent_.use_count() != 0 ) {
        if ( auto parent = parent_.lock() ) {
            const Rect parentAbsoluteContentRect = parent->getAbsoluteContentRect();
            return Rect(parentAbsoluteContentRect.getX() + rect_.getX() + contentRect_.getX(), parentAbsoluteContentRect.getY() + rect_.getY() + contentRect_.getY(), rect_.getWidth(), contentRect_.getHeight());
        } else
            throw std::runtime_error("parent should be there, but was not lockable");
    } else {
        const Rect parentAbsoluteContentRect(0, 0, 1, 1);
        return Rect(parentAbsoluteContentRect.getX() + rect_.getX() + contentRect_.getX(), parentAbsoluteContentRect.getY() + rect_.getY() + contentRect_.getY(), rect_.getWidth(), contentRect_.getHeight());
    }
}

void 
Widget::setCWPosition() {
    auto absoluteRect = getAbsoluteRect(); 
    cursesWindow_->move(absoluteRect.getX(), absoluteRect.getY());
}

void 
Widget::setCWSize() {
    auto absoluteRect = getAbsoluteRect();
    cursesWindow_->resize(absoluteRect.getWidth(), absoluteRect.getHeight());
}

void 
Widget::refresh() {
    Logger::get().log("Widget(%llx)::refresh()", this);
    setCWPosition(); // not necessary until we have a working move(), but what the bloody heck
    cursesWindow_->refresh();
}

void 
Widget::addString(const std::string& text) {
    Logger::get().log("Widget::addString(%s)", text.c_str());
    cursesWindow_->addString(text, contentRect_.getX(), contentRect_.getY());
}

void 
Widget::addString(const std::string& text, const int x, const int y) {
    Logger::get().log("Widget::addString(%s, %i, %i) adding text to contentRect_: (%i %i, %i, %i)", text.c_str(), x, y, contentRect_.getX(), contentRect_.getY(), contentRect_.getWidth(), contentRect_.getHeight());
    cursesWindow_->addString(text, contentRect_.getX() + x, contentRect_.getY() + y);
}

void 
Widget::addCh(int ch) {
    cursesWindow_->addCh(ch, contentRect_.getX(), contentRect_.getY());
}

void 
Widget::addCh(const int ch, const int x, const int y) {
    cursesWindow_->addCh(ch, contentRect_.getX() + x, contentRect_.getY() + y);
}

}
