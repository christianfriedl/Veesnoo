#include"Logger.h"
#include "ContainerFocusManager.h"

namespace nv {

ContainerFocusManager::ContainerFocusManager(std::shared_ptr<FocusableContainer> widget) : 
        ContainerFocusManaging(), focusedWidget_(NULL), isFocused_(false), _widget(widget) {
    Logger::get().log("new ContainerFocusManager @ %lld for widget @ %lld", this, *widget);
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
    // [app setFocusedWidget: widget];
    focusFirst();
}

void ContainerFocusManager::deFocus() {
    // [app setFocusedWidget: nil];
    isFocused_ = false;
}

void ContainerFocusManager::focusFirst() {
    auto subWidgets = getFocusableSubWidgets();
    if ( subWidgets.size() != 0)
        focusThis(subWidgets[0]);
}

auto ContainerFocusManager::getFocusableSubWidgets() {
    return std::copy_if(getSubWidgets(),
        [] (auto widget) { 
            FocusableWidget *f = dynamic_cast<FocusableWidget*> (widget.get()); // TODO find better way to do instanceof
            return ( f != NULL );
        });
}

void ContainerFocusManager::focusNext() {
    auto focusableSubWidgets = getFocusableSubWidgets();
        
    const FocusableWidget *res = NULL;
    int i=0;
    Logger::get().log("ContainerFocusManager @ %lld ::focusNext(), subWidgets have size %i", this, subWidgets.size());

    for (auto widget : subWidgets) {
        if (widget.get() == focusedWidget_.get()) {
            if (i == subWidgets.size() - 1)
                res = subWidgets[0];
            else
                res = subWidgets[i+1];
            break;
        } 
        ++i;
    }
    if ( res )
        focusThis(res);
}

void ContainerFocusManager::focusPrev() {
    auto subWidgets = getSubWidgets();
    const FocusableWidget *res = NULL;
    int i=subWidgets.size() - 1;
    for (std::vector<std::shared_ptr<const FocusableWidget> >::reverse_iterator iter = subWidgets.rbegin(); 
            iter != subWidgets.rend(); 
            ++iter) {
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

void ContainerFocusManager::focusThis(const FocusableWidget *widget) {
    auto subWidgets = getSubWidgets();

    focusedWidget_ = widget;
    if ( widget->isFocused() ) {
        return;
    }
    for ( std::vector<const FocusableWidget*>::iterator iter = subWidgets.begin(); 
            iter != subWidgets.end(); ++iter ) {
        if ( (*iter) == widget )
            (*iter)->focus();
        else
            (*iter)->deFocus();
    }
}

void ContainerFocusManager::focusThis(const int index) {
    auto subWidgets = getSubWidgets();
    if ( index >= subWidgets.size() )
        throw new Exception("out of bounds");
    focusThis(subWidgets[index]);
}

auto ContainerFocusManager::getSubWidgets() {
    return widget_.getSubWidgets();
}

void ContainerFocusManager::setWidget(const Widget&) {
    // TODO
}

bool ContainerFocusManager::isFocused() {
    return isFocused_;
}

}
