#include <memory>
#include <iostream>
#include <sstream>
#include "Rect.h"
#include "CursesWindow.h"
#include "Widget.h"
#include "Logger.h"
#include "CursesException.h"

namespace nv {

    Widget::Widget(): rect_(0, 0, 1, 1), contentRect_(0, 0, 1, 1), isVisible_(true), parent_(std::weak_ptr<Widget>()), primaryColorAttribute_(std::shared_ptr<ColorAttribute>()) { LOGMETHODONLY(); }

    std::shared_ptr<Widget> Widget::create(const Rect& rect) {
        return std::make_shared<Widget>(rect);
    }

    // constructor: set parent_ to "null", size from rect and make visible by default
    Widget::Widget(const Rect& rect): rect_(rect), contentRect_(0, 0, rect.getWidth(), rect.getHeight()), isVisible_(true), parent_(std::weak_ptr<Widget>()), primaryColorAttribute_(std::shared_ptr<ColorAttribute>()) {
        LOGMETHOD("new Widget %s", toString().c_str());

        cursesWindow_ = std::make_unique<CursesWindow>(this->getAbsoluteRect());
    }

    const std::string Widget::toString() const {
        std::ostringstream ostr;
        ostr << "<Widget @ " << std::hex << (unsigned long long int)this << std::dec << " rect: " << rect_.toString() << std::endl;
        ostr << "    contentRect_: " << contentRect_.toString() << std::endl;
        ostr << "    absoluteRect: " << getAbsoluteRect().toString() << std::endl;
        ostr << "    absoluteContentRect: " << getAbsoluteContentRect().toString() << std::endl;
        ostr << ">";
        return ostr.str();
    }

    void Widget::resize(const int width, const int height) {
        Logger::get().log("Widget(%llx)::resize(%i, %i)", this, width, height);
        rect_.resize(width, height);
        contentRect_.resize(width, height);
        cursesWindow_->resize(width, height);
    }

    void Widget::move(const int x, const int y) {
        rect_.move(x, y);
        cursesWindow_->move(getAbsoluteRect().getX(), getAbsoluteRect().getY());
    }

    const std::weak_ptr<Widget>& Widget::getParent() const {
        return parent_;
    }

    void Widget::startColorAttribute(const ColorAttribute& attribute) {
        cursesWindow_->startColorAttribute(attribute);
    }

    void Widget::endColorAttribute(const ColorAttribute& attribute) {
        cursesWindow_->endColorAttribute(attribute);
    }

    void Widget::startColorAttribute(std::shared_ptr<ColorAttribute> attribute) {
        cursesWindow_->startColorAttribute(attribute);
    }

    void Widget::endColorAttribute(std::shared_ptr<ColorAttribute> attribute) {
        cursesWindow_->endColorAttribute(attribute);
    }

    bool Widget::getIsVisible() const {
        return isVisible_;
    }

    bool Widget::getIsVisibleBubbling() const {
        if ( !isVisible_ )
            return false;
        if ( parent_.use_count() != 0 ) {
            if ( auto parent = parent_.lock() ) {
                return parent->getIsVisibleBubbling();
            } else
                throw std::runtime_error("parent is there but cannot be locked");
        } else
            return true;
    }

    void Widget::show() {
        isVisible_ = true;
    }

    void Widget::hide() {
        isVisible_ = false;
    }

    void Widget::setParent(const std::weak_ptr<Widget>& parent) {
        parent_ = parent;
    }


    Rect Widget::getRect() const {
        return rect_;
    }

    Rect Widget::getContentRect() const {
        return contentRect_;
    }

    Rect Widget::getAbsoluteRect() const {
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

    Rect Widget::getAbsoluteContentRect() const {
        if ( parent_.use_count() != 0 ) {
            if ( auto parent = parent_.lock() ) {
                const Rect parentAbsoluteContentRect = parent->getAbsoluteContentRect();
                return Rect(parentAbsoluteContentRect.getX() + rect_.getX() + contentRect_.getX(), parentAbsoluteContentRect.getY() + rect_.getY() + contentRect_.getY(), contentRect_.getWidth(), contentRect_.getHeight());
            } else
                throw std::runtime_error("parent should be there, but was not lockable");
        } else {
            const Rect parentAbsoluteContentRect(0, 0, 1, 1);
            return Rect(parentAbsoluteContentRect.getX() + rect_.getX() + contentRect_.getX(), parentAbsoluteContentRect.getY() + rect_.getY() + contentRect_.getY(), contentRect_.getWidth(), contentRect_.getHeight());
        }
    }

    Rect Widget::getParentAbsoluteContentRect() const {
        if ( parent_.use_count() != 0 ) {
            if ( auto parent = parent_.lock() ) {
                return parent->getAbsoluteContentRect();
            } else
                throw std::runtime_error("parent should be there, but was not lockable");
        } else {
            return Rect(0, 0, 0, 0);
        }
    }

    void Widget::setCWPosition(const Rect& absoluteRect) {
        if ( getParentAbsoluteContentRect().covers(absoluteRect) ) {
            cursesWindow_->move(absoluteRect.getX(), absoluteRect.getY());
        } else {
            LOGMETHOD("absoluteRect %s NOT covered by parentAbsoluteRect %s - unable to move curseswindow to %i, %i", absoluteRect.toString().c_str(), getParentAbsoluteContentRect().toString().c_str(), absoluteRect.getX(), absoluteRect.getY());
        }
    }

    void Widget::setCWSize() {
        auto absoluteRect = getAbsoluteRect();
        cursesWindow_->resize(absoluteRect.getWidth(), absoluteRect.getHeight());
    }

    void Widget::refresh() {
        LOGMETHODONLY();
        if ( !getIsVisibleBubbling() )
            return;
        setCWPosition(getAbsoluteRect()); // TODO check if still valid: not necessary until we have a working move(), but what the bloody heck
        cursesWindow_->noutrefresh();
        if ( parent_.use_count() == 0 ) {
            CursesManager::get().refresh();
        }
    }

    std::shared_ptr<ColorAttribute> Widget::getPrimaryColorAttribute() {
        auto colAttr = primaryColorAttribute_;
        if ( colAttr.use_count() == 0 && parent_.use_count() > 0 )
            colAttr = parent_.lock()->getPrimaryColorAttribute();
        if ( colAttr.use_count() == 0 )
            colAttr = std::make_shared<ColorAttribute>(COLOR_YELLOW, COLOR_BLUE);
        LOGMETHOD("colAttr = %s", colAttr->toString().c_str());
        return colAttr;
    }

    void Widget::addString(const std::string& text) {
        Logger::get().log("Widget::addString(%s)", text.c_str());
        startColorAttribute(getPrimaryColorAttribute());
        cursesWindow_->addString(text, contentRect_.getX(), contentRect_.getY());
        endColorAttribute(getPrimaryColorAttribute());
    }

    void Widget::addString(const std::string& text, const int x, const int y) {
        Logger::get().log("Widget::addString(%s, %i, %i) adding text to contentRect_: (%i %i, %i, %i)", text.c_str(), x, y, contentRect_.getX(), contentRect_.getY(), contentRect_.getWidth(), contentRect_.getHeight());
        startColorAttribute(getPrimaryColorAttribute());
        cursesWindow_->addString(text, contentRect_.getX() + x, contentRect_.getY() + y);
        endColorAttribute(getPrimaryColorAttribute());
    }

    void Widget::addCh(int ch) {
        startColorAttribute(getPrimaryColorAttribute());
        cursesWindow_->addCh(ch, contentRect_.getX(), contentRect_.getY());
        endColorAttribute(getPrimaryColorAttribute());
    }

    void Widget::addCh(const int ch, const int x, const int y) {
        startColorAttribute(getPrimaryColorAttribute());
        cursesWindow_->addCh(ch, contentRect_.getX() + x, contentRect_.getY() + y);
        endColorAttribute(getPrimaryColorAttribute());
    }

}
