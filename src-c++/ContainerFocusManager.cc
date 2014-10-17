#include "ContainerFocusManager.h"

namespace nv {

void addWidget(Focusable *widget) {
    subWidgets_.push_back(widget);
}

bool receiveKey(int ch) {
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

void focus() {
    isFocused = true;
    // [app setFocusedWidget: widget];
    focusFirst();
}

void deFocus() {
    // [app setFocusedWidget: nil];
    isFocused = false;
}

-(void) focusFirst {
    if ( subWidgets.size() != 0)
        focusThis(subWidgets[0]);
}

void focusNext() {
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

-(void) focusPrev {
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

}
