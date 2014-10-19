       #include <stdio.h>
       #include <stdlib.h>

#include "ContainerFocusManager.h"

namespace nv {

ContainerFocusManager::ContainerFocusManager(FocusableContainer& widget) : 
        ContainerFocusManaging(), widget_(&widget), focusedWidget_(NULL), isFocused_(false) {
            endwin();
            printf("f not null");
            exit(0);
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

/*
-(void) focusThis: (Widget<KeyReceiving>*) awidget {
    int i = 0, count = [subWidgets count];
    for (i=0; i < count; ++i) {
        Widget<KeyReceiving>* focusable = [subWidgets objectAtIndex: i];
        if (![focusable isEqual: awidget] && [focusable isFocused])
            [focusable deFocus];
    }
    [awidget focus];
    focusedWidget = awidget;
}
*/

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
    // TODO: use for loop, it's much easier that way!
    /*
     *
    int i = 0, count = [subWidgets count];
    if (count == 0)
        return;
    if (focusedWidget != nil)
        i = [subWidgets indexOfObject: focusedWidget];
    if (i == count - 1)
        i = 0;
    else
        ++i;
    [self focusThis: [subWidgets objectAtIndex: i]];
    */
}

void ContainerFocusManager::focusPrev() {
    /*
    int i = 0, count = [subWidgets count];
    if (count == 0)
        return;
    if (focusedWidget != nil)
        i = [subWidgets indexOfObject: focusedWidget];
    if (i == 0)
        i = count - 1;
    else
        --i;
    [self focusThis: [subWidgets objectAtIndex: i]];
    */
}

void ContainerFocusManager::focusThis(const Focusable *widget) {
    if ( widget->isFocused() ) {
        return;
    }
    for ( std::vector<Focusable*>::iterator iter = subWidgets_.begin(); iter != subWidgets_.end(); ++iter) {
        if ( (*iter) == widget )
            (*iter)->focus();
        else
            (*iter)->deFocus();
    }
}

void ContainerFocusManager::setWidget(const Widget&) {
    // TODO
}

bool ContainerFocusManager::isFocused() {
    return isFocused_;
}

}
