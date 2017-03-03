#ifndef NV_CONTAINER_FOCUS_MANAGER_H
#define NV_CONTAINER_FOCUS_MANAGER_H

#include <vector>
#include "Widget.h"
#include "Focusable.h"

namespace nv {

class FocusableContainer;

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
    void focusThis(std::shared_ptr<Focusable>& widget);

private:
    std::vector<std::shared_ptr<Widget>> getSubWidgets();
    std::vector<std::shared_ptr<Focusable>> getFocusableSubWidgets();

    FocusableContainer *widget_;
    std::shared_ptr<Focusable> focusedWidget_;
    bool isFocused_;
    // std::vector<std::shared_ptr<Focusable>>(tmpSubWidgets.size()) focusableSubWidgets_; // only ever used temporarily

};

}

#endif
