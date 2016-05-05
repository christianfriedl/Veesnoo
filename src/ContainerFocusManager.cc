#include<algorithm>
#include"Logger.h"
#include "ContainerFocusManager.h"

namespace nv {

ContainerFocusManager::ContainerFocusManager(const std::weak_ptr<FocusableContainer>& widget) : 
        ContainerFocusManaging(), widget_(widget), focusedWidget_(NULL), isFocused_(false) {
    // Logger::get().log("new ContainerFocusManager @ %lld for widget @ %lld", this, widget.get());
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
    if (auto widget = widget_.lock())
        return widget.get()->getSubWidgets();
    else
        return std::vector<std::shared_ptr<Widget>>();
}


std::vector<std::shared_ptr<FocusableWidget>> ContainerFocusManager::getFocusableSubWidgets() {
    auto subWidgets = getSubWidgets();
    auto tmpSubWidgets = std::vector<std::shared_ptr<Widget>>(subWidgets.size());
    auto it = std::copy_if(subWidgets.begin(), subWidgets.end(), tmpSubWidgets.begin(),
        [] (auto widget) { 
            FocusableWidget *f = dynamic_cast<FocusableWidget*> (widget.get()); // TODO find better way to do instanceof
            return ( f != NULL );
        });
    tmpSubWidgets.resize(std::distance(tmpSubWidgets.begin(), it));

    auto focusableSubWidgets = std::vector<std::shared_ptr<FocusableWidget>>(tmpSubWidgets.size());
    for (auto widget: tmpSubWidgets) { // TODO i'm sure there is a better way for copying to vector of subtype
        FocusableWidget *f = dynamic_cast<FocusableWidget*> (widget.get());
        focusableSubWidgets.emplace_back(std::shared_ptr<FocusableWidget>(f));
    }

    return focusableSubWidgets; // copied
}

void ContainerFocusManager::focusFirst() {
    auto focusableSubWidgets = getFocusableSubWidgets();

    if (focusableSubWidgets.size() != 0)
        focusThis(focusableSubWidgets[0]);
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

void ContainerFocusManager::focusThis(const std::shared_ptr<FocusableWidget>& widget) {
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

bool ContainerFocusManager::isFocused() {
    return isFocused_;
}

}
