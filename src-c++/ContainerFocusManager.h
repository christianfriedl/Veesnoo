#ifndef NV_CONTAINER_FOCUS_MANAGER_H
#define NV_CONTAINER_FOCUS_MANAGER_H

#include <vector>
#include <ncurses.h>
#include "Widget.h"
#include "FocusableWidget.h"
#include "FocusManaging.h"

namespace nv {

class ContainerFocusManager : public FocusManaging { 

public:
    ContainerFocusManager(FocusableWidget& widget) : 
            FocusManaging(), widget_(&widget), focusedWidget_(NULL), 
            subWidgets_(std::vector<Widget*>), isFocused_(false) {
        for (std::vector<Widget*>::iterator iter = subWidgets_->begin(); iter != subWidgets_->end(); ++iter) {
            if ( (FocusableWidget *f = dynamic_cast<FocusableWidget*> (*iter)) ) {
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
private:

    Focusable *widget_;
    Focusable *focusedWidget_;
    std::vector<Focusable *> subWidgets_;
    bool isFocused_;

    void focusThis(Focusable *widget);


}

}

#endif
