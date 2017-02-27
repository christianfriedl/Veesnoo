#include <iostream>
#include "Widget.h"
#include <stdexcept>


static int numWidgets = 1;

Widget::Widget(): i_(numWidgets++), manager_(), sub_(nullptr), parent_(std::weak_ptr<Widget>()) {
    manager_.setWidget(this);
}

Widget::~Widget() {
    std::cout << "~widget() " << this << std::endl;
}

void Widget::paint() { 
    std::cout << "Widget::paint()" << std::endl;
}

void Widget::changeInternals() { 
    i_ = 23;
}

void Widget::addOwnSub() { 
    setSub(std::make_shared<Widget>());
}

void Widget::setSub(const std::shared_ptr<Widget>& sub) { 
    sub_ = sub; 
    std::weak_ptr<Widget> weakThis = shared_from_this();
    sub_->setParent(weakThis);
}

const std::weak_ptr<Widget>& Widget::getParent() const { 
    return parent_;
}

void Widget::setParent(const std::weak_ptr<Widget>& parent) { 
    {
        auto sharedParent = parent.lock();
        std::cout << "will set parent to " << sharedParent << std::endl;
    }
    parent_ = parent;
}

const std::shared_ptr<Widget>& Widget::getSub() { return sub_; }

std::ostream& operator<<(std::ostream& os, const Widget& widget) {
    os << "widget {i=" << widget.i_ << ", sub=" << widget.sub_ << "}";
    return os;
}
