#ifndef NV_FOCUSABLE_CONTAINER_H
#define NV_FOCUSABLE_CONTAINER_H

#include <memory>
#include "Focusable.h"
#include "FocusableWidget.h"
#include "Container.h"
#include "ContainerFocusManager.h"

namespace nv {

class ContainerFocusManager;

class FocusableContainer: public Focusable, public Container {
public:
    explicit FocusableContainer(const Rect& rect): Focusable(), Container(rect), focusManager_(this) { }

    FocusableContainer(const Rect& rect, const ContainerFocusManager& focusManager): Focusable(), Container(rect), focusManager_(focusManager) { }
    void setFocusManager(const ContainerFocusManager& focusManager) { focusManager_ = focusManager; }

    virtual ~FocusableContainer() {}

    // from Focusable, which is just an interface
    virtual bool receiveKey(int ch);

    virtual bool isFocused() const { return focusManager_.isFocused(); }
    virtual void focus() { return focusManager_.focus(); }
    virtual void deFocus() { return focusManager_.deFocus(); }

    void focusFirst() { focusManager_.focusFirst(); }
    void focusNext() { focusManager_.focusNext(); }
    void focusPrev() { focusManager_.focusPrev(); }
    void focusThis(FocusableWidget *widget) { focusManager_.focusThis(widget); }

protected:
    ContainerFocusManager focusManager_;
private:
};

}
#endif
