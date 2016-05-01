#ifndef NV_FOCUSABLE_CONTAINER_H
#define NV_FOCUSABLE_CONTAINER_H

#include <memory>
#include "Focusable.h"
#include "FocusableWidget.h"
#include "Container.h"
#include "ContainerFocusManaging.h"

namespace nv {

class FocusableContainer: public Focusable, public Container {
public:
    FocusableContainer(const Rect& rect): Focusable(), Container(rect), focusManager_() { }

    FocusableContainer(const Rect& rect, std::unique_ptr<ContainerFocusManaging> focusManager): Focusable(), Container(rect), focusManager_(std::move(focusManager)) { }
    virtual ~FocusableContainer() {}

    // from Focusable, which is just an interface
    virtual bool receiveKey(int ch);

    virtual bool isFocused() const { return focusManager_->isFocused(); }
    virtual void focus() { return focusManager_->focus(); }
    virtual void deFocus() { return focusManager_->deFocus(); }

    void focusFirst() { focusManager_->focusFirst(); }
    void focusNext() { focusManager_->focusNext(); }
    void focusPrev() { focusManager_->focusPrev(); }
    void focusThis(std::shared_ptr<FocusableWidget> widget) { focusManager_->focusThis(widget); }
    void focusThis(const int index) { focusManager_->focusThis(index); }

protected:
    std::unique_ptr<ContainerFocusManaging> focusManager_;
private:
};

}
#endif
