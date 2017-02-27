#include <iostream>
#include "Manager.h"
#include "Widget.h"

Manager::Manager(): j_(2), widget_{NULL} {}

Manager::~Manager() {
    std::cout << "~Manager()" << std::endl;
}


void Manager::setWidget(Widget *widget) { 
    std::cout << "Manager::setWidget() to " << widget << std::endl; 
    widget_ = widget;
}

std::ostream& operator<<(std::ostream& os, const Manager& m) {
    os << "{ Manager, j=" << m.j_ << " widget * is " << m.widget_ << "}";
    return os;
}

