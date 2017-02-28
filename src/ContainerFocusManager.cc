#include<algorithm>
#include"Logger.h"
#include "ContainerFocusManager.h"
#include "FocusableContainer.h"

namespace nv {

ContainerFocusManager::ContainerFocusManager(FocusableContainer *widget) : 
        widget_(widget), focusedWidget_(nullptr), isFocused_(false) {
}

bool ContainerFocusManager::receiveKey(int ch) {
    if (ch == ' ' || ch == '\t' || ch == KEY_STAB || ch == KEY_DOWN || ch == KEY_RIGHT || ch == 'j' || ch == 'l') {
        focusNext();
        return true;
    }
    else if (ch == KEY_BACKSPACE || ch == KEY_BTAB || ch == KEY_UP || ch == KEY_LEFT || ch == 'k' || ch == 'h') {
        focusPrev();
        return true;
    }
    return false;
}

void ContainerFocusManager::focus() {
    isFocused_ = true;
    focusFirst();
}

void ContainerFocusManager::deFocus() {
    // [app setFocusedWidget: nil];
    isFocused_ = false;
}

auto ContainerFocusManager::getSubWidgets() {
    return widget_->getSubWidgets();
}


std::vector<std::shared_ptr<FocusableWidget>> ContainerFocusManager::getFocusableSubWidgets() {
    auto subWidgets = getSubWidgets();
    auto focusableSubWidgets = std::vector<std::shared_ptr<FocusableWidget>>();

    for ( auto widget: subWidgets ) {
        auto f = std::dynamic_pointer_cast<FocusableWidget>(widget);
        if ( f.get() != nullptr )
            focusableSubWidgets.emplace_back(f);
    }

    return focusableSubWidgets;
}

void ContainerFocusManager::focusFirst() {
    auto focusableSubWidgets = getFocusableSubWidgets();

    if ( focusableSubWidgets.size() != 0 )
        focusThis(focusableSubWidgets.front());
}

void ContainerFocusManager::focusNext() {
    auto focusableSubWidgets = getFocusableSubWidgets();
        
    if (focusableSubWidgets.size() != 0) {
        std::shared_ptr<FocusableWidget> res;
        int i=0;

        for (auto widget : focusableSubWidgets) {
            if (widget.get() == focusedWidget_.get()) {
                if (i == focusableSubWidgets.size() - 1)
                    res = focusableSubWidgets[0];
                else
                    res = focusableSubWidgets[i+1];
                break;
            } 
            ++i;
        }
        if (res)
            focusThis(res);
    }
}

void ContainerFocusManager::focusPrev() {
    auto focusableSubWidgets = getFocusableSubWidgets();

    if (focusableSubWidgets.size() != 0) {
        std::shared_ptr<FocusableWidget> res;
        int i = focusableSubWidgets.size() - 1;
        for (std::vector<std::shared_ptr<FocusableWidget> >::reverse_iterator iter = focusableSubWidgets.rbegin(); 
                iter != focusableSubWidgets.rend(); ++iter) {
            if ((*iter) == focusedWidget_) {
                if (i == 0)
                    res = focusableSubWidgets[focusableSubWidgets.size() - 1];
                else
                    res = focusableSubWidgets[i-1];
                break;
            } 
            --i;
        }
        if ( res )
            focusThis(res);
    }
}

void ContainerFocusManager::focusThis(std::shared_ptr<FocusableWidget>& widget) {
    auto focusableSubWidgets = getFocusableSubWidgets();

    focusedWidget_ = widget;
    if ( widget->isFocused() ) {
        return;
    }
    for ( auto widget: focusableSubWidgets ) {
        if ( focusedWidget_.get() == widget.get() )
            widget->focus();
        else
            widget->deFocus();
    }
}

bool ContainerFocusManager::isFocused() const {
    return isFocused_;
}

}
