#ifndef NV_CONTAINER_FOCUS_MANAGER_H
#define NV_CONTAINER_FOCUS_MANAGER_H

#include <vector>
#include <ncursesw/ncurses.h>
#include "Widget.h"
#include "FocusableContainer.h"
#include "FocusableWidget.h"
#include "ContainerFocusManaging.h"

namespace nv {

class ContainerFocusManager : public ContainerFocusManaging { 

public:
    explicit ContainerFocusManager(const FocusableContainer& widget);

    bool receiveKey(int ch);
    void focus();
    void deFocus();
    void focusFirst();
    void focusNext();
    void focusPrev();
    virtual void addWidget(const Widget& widget);
    void setWidget(const Widget&);
    bool isFocused();
    void focusThis(const FocusableWidget *widget);
    void focusThis(const int index);

private:

    std::shared_ptr<FocusableWidget> focusedWidget_;
    std::vector<std::shared_ptr<FocusableWidget>> subWidgets_;
    bool isFocused_;


};

}

#endif
