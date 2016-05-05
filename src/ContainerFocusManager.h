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
    explicit ContainerFocusManager(const std::weak_ptr<FocusableContainer>& widget);
    virtual ~ContainerFocusManager() {}

    void setWidget(std::shared_ptr<Container> widget) { widget_ = widget; }

    bool receiveKey(int ch);
    void focus();
    void deFocus();
    void focusFirst();
    void focusNext();
    void focusPrev();
    bool isFocused();
    void focusThis(const std::shared_ptr<FocusableWidget>& widget);

private:
    auto getSubWidgets();
    std::vector<std::shared_ptr<FocusableWidget>> getFocusableSubWidgets();

    std::weak_ptr<Container> widget_;
    std::shared_ptr<FocusableWidget> focusedWidget_;
    bool isFocused_;
    // std::vector<std::shared_ptr<FocusableWidget>>(tmpSubWidgets.size()) focusableSubWidgets_; // only ever used temporarily

};

}

#endif
