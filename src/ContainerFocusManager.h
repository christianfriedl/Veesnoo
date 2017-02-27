#ifndef NV_CONTAINER_FOCUS_MANAGER_H
#define NV_CONTAINER_FOCUS_MANAGER_H

#include <vector>
#include <ncurses.h>
#include "Widget.h"
#include "FocusableContainer.h"
#include "FocusableWidget.h"

namespace nv {

class ContainerFocusManager { 

public:
    explicit ContainerFocusManager(FocusableContainer *widget);
    virtual ~ContainerFocusManager() {}

    void setWidget(FocusableContainer *widget) { widget_ = widget; }

    bool receiveKey(int ch);
    void focus();
    void deFocus();
    void focusFirst();
    void focusNext();
    void focusPrev();
    bool isFocused() const;
    void focusThis(FocusableWidget *widget);

private:
    auto getSubWidgets();
    std::vector<std::shared_ptr<FocusableWidget>> getFocusableSubWidgets();

    FocusableContainer *widget_;
    FocusableWidget *focusedWidget_;
    bool isFocused_;
    // std::vector<std::shared_ptr<FocusableWidget>>(tmpSubWidgets.size()) focusableSubWidgets_; // only ever used temporarily

};

}

#endif
