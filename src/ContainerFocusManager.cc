#include"Logger.h"
#include "ContainerFocusManager.h"

namespace nv {

ContainerFocusManager::ContainerFocusManager(FocusableContainer& widget) : 
        ContainerFocusManaging(), widget_(&widget), focusedWidget_(NULL), isFocused_(false) {
    Logger::get().log("new ContainerFocusManager @ %ld for widget @ %ld", this, &widget);
    subWidgets_ = std::vector<const FocusableWidget*>();
    // add all subwidgets that are focusable to our collection
    for ( std::vector<Widget*>::iterator iter = widget.getSubWidgets().begin(); iter != widget.getSubWidgets().end(); ++iter ) {
        FocusableWidget *f = dynamic_cast<FocusableWidget*> (*iter);
        if ( f != NULL ) {
            subWidgets_.push_back(f);
        }
    }
}

void ContainerFocusManager::addWidget(const Widget& widget) {
    const FocusableWidget *f = dynamic_cast<const FocusableWidget*>(&widget);
    Logger::get().log("ContainerFocusManager @ %ld for widget @ %ld will add widget %ld", this, widget_, &widget);
    if (f != NULL)
        subWidgets_.push_back(f);
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
    if ( subWidgets_.size() != 0)
        focusThis(subWidgets_[0]);
}

void ContainerFocusManager::focusNext() {
    const FocusableWidget *res = NULL;
    int i=0;
    Logger::get().log("ContainerFocusManager @ %ld ::focusNext(), subWidgets_ have size %i", this, subWidgets_.size());

    for (std::vector<const FocusableWidget *>::iterator iter = subWidgets_.begin(); 
            iter != subWidgets_.end(); 
            ++iter) {
        if ((*iter) == focusedWidget_) {
            if (i == subWidgets_.size() - 1)
                res = subWidgets_[0];
            else
                res = subWidgets_[i+1];
            break;
        } 
        ++i;
    }
    focusThis(res);
}

void ContainerFocusManager::focusPrev() {
    const FocusableWidget *res = NULL;
    int i=subWidgets_.size() - 1;
    for (std::vector<const FocusableWidget *>::reverse_iterator iter = subWidgets_.rbegin(); 
            iter != subWidgets_.rend(); 
            ++iter) {
        if ((*iter) == focusedWidget_) {
            if (i == 0)
                res = subWidgets_[subWidgets_.size() - 1];
            else
                res = subWidgets_[i-1];
            break;
        } 
        --i;
    }
    focusThis(res);
}

void ContainerFocusManager::focusThis(const FocusableWidget *widget) {
    focusedWidget_ = widget;
    if ( widget->isFocused() ) {
        return;
    }
    for ( std::vector<const FocusableWidget*>::iterator iter = subWidgets_.begin(); 
            iter != subWidgets_.end(); ++iter ) {
        if ( (*iter) == widget )
            (*iter)->focus();
        else
            (*iter)->deFocus();
    }
}

void ContainerFocusManager::focusThis(const int index) {
    if ( index >= subWidgets_.size() )
        throw new Exception("out of bounds");
    focusThis(subWidgets_[index]);
}

void ContainerFocusManager::setWidget(const Widget&) {
    // TODO
}

bool ContainerFocusManager::isFocused() {
    return isFocused_;
}

}
