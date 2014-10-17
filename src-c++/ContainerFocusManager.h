#ifndef NV_CONTAINER_FOCUS_MANAGER_H
#define NV_CONTAINER_FOCUS_MANAGER_H

#include <vector>
#include <ncursesw/ncurses.h>
#include "Widget.h"
#include "FocusableContainer.h"
#include "FocusableWidget.h"
#include "FocusManaging.h"

namespace nv {

class ContainerFocusManager : public FocusManaging { 

public:
    ContainerFocusManager(FocusableContainer& widget) : 
            FocusManaging(), widget_(&widget), focusedWidget_(NULL), isFocused_(false) {
        subWidgets_ = std::vector<Focusable*>();
        // add all subwidgets that are focusable to our collection
        for ( std::vector<Widget*>::iterator iter = widget.getSubWidgets().begin(); iter != widget.getSubWidgets().end(); ++iter ) {
            FocusableWidget *f = dynamic_cast<FocusableWidget*> (*iter);
            if ( f != NULL ) {
                subWidgets_.push_back(f);
            }
        }
    }

    bool receiveKey(int ch);
    void focus();
    void deFocus();
    void focusFirst();
    void focusNext();
    void focusPrev();
    void addWidget(Focusable *widget);
    void setWidget(const Widget&);
    bool isFocused();
private:

    Focusable *widget_;
    Focusable *focusedWidget_;
    std::vector<Focusable *> subWidgets_;
    bool isFocused_;

    void focusThis(Focusable *widget);


};

}

#endif
