#include<algorithm>
#include"Logger.h"
#include "ContainerFocusManager.h"

namespace nv {

ContainerFocusManager::ContainerFocusManager(std::shared_ptr<FocusableContainer> widget) : 
        ContainerFocusManaging(), widget_(widget), focusedWidget_(NULL), isFocused_(false) {
    Logger::get().log("new ContainerFocusManager @ %lld for widget @ %lld", this, widget.get());
    // add all subwidgets that are focusable to our collection
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
    return widget_.get()->getSubWidgets();
}


auto ContainerFocusManager::getFocusableSubWidgets() {
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
        FocusableWidget *f = dynamic_cast<FocusableWidget*> (widget.get()); // TODO find better way to do instanceof
        focusableSubWidgets.push_back(std::shared_ptr<FocusableWidget>(f));
    }

    return focusableSubWidgets;
}

void ContainerFocusManager::focusFirst() {
    auto subWidgets = getFocusableSubWidgets();
    if ( subWidgets.size() != 0)
        focusThis(subWidgets[0]);
}

void ContainerFocusManager::focusNext() {
    auto focusableSubWidgets = getFocusableSubWidgets();
        
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
    if ( res )
        focusThis(res);
}

void ContainerFocusManager::focusPrev() {
    auto subWidgets = getFocusableSubWidgets();

    std::shared_ptr<FocusableWidget> res;
    int i = subWidgets.size() - 1;
    for (std::vector<std::shared_ptr<FocusableWidget> >::reverse_iterator iter = subWidgets.rbegin(); 
            iter != subWidgets.rend(); ++iter) {
        if ((*iter) == focusedWidget_) {
            if (i == 0)
                res = subWidgets[subWidgets.size() - 1];
            else
                res = subWidgets[i-1];
            break;
        } 
        --i;
    }
    if ( res )
        focusThis(res);
}

void ContainerFocusManager::focusThis(std::shared_ptr<FocusableWidget> widget) {
    auto subWidgets = getFocusableSubWidgets();

    focusedWidget_ = widget;
    if ( widget->isFocused() ) {
        return;
    }
    for ( auto widget: subWidgets ) {
        if ( focusedWidget_.get() == widget.get() )
            widget->focus();
        else
            widget->deFocus();
    }
}

void ContainerFocusManager::focusThis(const int index) {
    auto subWidgets = getFocusableSubWidgets();
    focusThis(subWidgets[index]);
}

bool ContainerFocusManager::isFocused() {
    return isFocused_;
}

}
