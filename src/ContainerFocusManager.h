#ifndef NV_CONTAINER_FOCUS_MANAGER_H
#define NV_CONTAINER_FOCUS_MANAGER_H

#include <vector>
#include "Widget.h"
#include "Focusable.h"
#include "FocusableWidget.h"

namespace nv {

class FocusableContainer;

class ContainerFocusManager { 

public:
    explicit ContainerFocusManager(FocusableContainer *widget);
    virtual ~ContainerFocusManager() {}

    void setWidget(FocusableContainer *widget) { widget_ = widget; }

    bool receiveKey(int ch);
    void focus();
    void blur();
    void focusFirst();
    void focusNext();
    void focusPrev();
    bool isFocused() const;
    void focusThis(std::shared_ptr<Focusable>& widget); // focus this direct subwidget of ours
    void requestFocus(std::shared_ptr<Focusable> widget); // subwidget, or sub-subwidget, wants the focus
    std::shared_ptr<Focusable> getFocusedWidget();

private:
    std::vector<std::shared_ptr<Widget>> getSubWidgets();
    std::vector<std::shared_ptr<Focusable>> getFocusableSubWidgets();
    bool bubbleReceiveKey(int ch, std::shared_ptr<Widget> w);

    FocusableContainer *widget_;
    std::shared_ptr<Focusable> focusedWidget_;
    bool isFocused_;
    // std::vector<std::shared_ptr<Focusable>>(tmpSubWidgets.size()) focusableSubWidgets_; // only ever used temporarily

};

}

#endif
