#include<algorithm>
#include"Logger.h"
#include "ContainerFocusManager.h"
#include "FocusableContainer.h"
#include "FocusableWidget.h"

namespace nv {

ContainerFocusManager::ContainerFocusManager(FocusableContainer *widget) : 
        widget_(widget), focusedWidget_(nullptr), isFocused_(false) {
}

std::shared_ptr<Focusable> 
ContainerFocusManager::getFocusedWidget() {
    return focusedWidget_;
}


bool ContainerFocusManager::bubbleReceiveKey(int ch, std::shared_ptr<Widget> w) {
    auto f = std::dynamic_pointer_cast<Focusable> (w);
    if ( !f ) throw Exception("w is not focusable");
    if ( f.get() == dynamic_cast<Focusable*>(widget_) )
        return false;
    else if ( f->receiveKey(ch) )
        return true;
    else {
        auto ff = w->getParent().lock();
        if ( !ff )
            return false;
        return bubbleReceiveKey(ch, ff);
    }
}

bool ContainerFocusManager::receiveKey(int ch) {
    auto fw = focusedWidget_;
    if ( fw )  {
        if ( bubbleReceiveKey(ch, std::dynamic_pointer_cast<Widget>(fw)) )
            return true;
    } else {
        focusFirst();
        return true;
    }
        
    if (ch == ' ' || ch == '\t' || ch == KEY_STAB || ch == KEY_DOWN || ch == KEY_RIGHT || ch == 'j' || ch == 'l') {
        focusNext();
        return true;
    }
    else if (ch == KEY_BACKSPACE || ch == KEY_BTAB || ch == KEY_UP || ch == KEY_LEFT || ch == 'k' || ch == 'h') {
        focusPrev();
        return true;
    }
    else
        return false;
}

void ContainerFocusManager::focus() {
    Logger::get().log("ContainerFocusManager @ %llx is focused, will focusFirst() on subwids length %i, fsw le %i", this, getSubWidgets().size(), getFocusableSubWidgets().size()),
    isFocused_ = true;
    focusFirst();
}

void ContainerFocusManager::blur() {
    // [app setFocusedWidget: nil];
    isFocused_ = false;
}
std::vector<std::shared_ptr<Widget>> 
ContainerFocusManager::getSubWidgets() {
    return widget_->getSubWidgets();
}


std::vector<std::shared_ptr<Focusable>> ContainerFocusManager::getFocusableSubWidgets() {
    auto subWidgets = getSubWidgets();
    auto focusableSubWidgets = std::vector<std::shared_ptr<Focusable>>();

    for ( auto widget: subWidgets ) {
        if ( widget->getIsVisibleBubbling() ) {
            auto f = std::dynamic_pointer_cast<Focusable>(widget);
            if ( f.get() != nullptr )
                focusableSubWidgets.emplace_back(f);
        }
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
        std::shared_ptr<Focusable> res;
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
        std::shared_ptr<Focusable> res;
        int i = focusableSubWidgets.size() - 1;
        for (std::vector<std::shared_ptr<Focusable> >::reverse_iterator iter = focusableSubWidgets.rbegin(); 
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

void ContainerFocusManager::focusThis(std::shared_ptr<Focusable>& widget) {
    // Logger::get().log("ContainerFocusManager will focus widget: %s", widget->toString().c_str());
    auto focusableSubWidgets = getFocusableSubWidgets();

    focusedWidget_ = widget;
    if ( widget->isFocused() ) {
        return;
    }
    for ( auto widget: focusableSubWidgets ) {
        if ( focusedWidget_.get() == widget.get() )
            widget->focus();
        else
            widget->blur();
    }
}

bool ContainerFocusManager::isFocused() const {
    return isFocused_;
}

void ContainerFocusManager::subWidgetHasFocused(std::shared_ptr<Focusable> widget) {
    std::shared_ptr<Widget> w = widget_->getParent().lock();
    if ( w ) {
        auto w2 = std::dynamic_pointer_cast<FocusableContainer>(w);
        if ( !w2 )
            throw Exception("could not cast parent to FocusableContainer");
        w2->subWidgetHasFocused(widget);
    } else
        focusedWidget_ = widget;
}

}
