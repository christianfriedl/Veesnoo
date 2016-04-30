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
    explicit ContainerFocusManager(std::shared_ptr<FocusableContainer> widget);

    bool receiveKey(int ch);
    void focus();
    void deFocus();
    void focusFirst();
    void focusNext();
    void focusPrev();
    bool isFocused();
    void focusThis(std::shared_ptr<FocusableWidget> widget);
    void focusThis(const int index);

private:
    auto getSubWidgets();
    auto getFocusableSubWidgets();

    std::shared_ptr<Container> widget_; // TODO this might be a weak_ptr??
    std::shared_ptr<FocusableWidget> focusedWidget_;
    bool isFocused_;

};

}

#endif
