#ifndef NV_FOCUSABLE_CONTAINER_H
#define NV_FOCUSABLE_CONTAINER_H

#include "Focusable.h"
#include "FocusableWidget.h"
#include "Container.h"
#include "ContainerFocusManaging.h"

namespace nv {

class FocusableContainer: public Focusable, public Container {
public:
    FocusableContainer(const Rect& rect): Focusable(), Container(rect), focusManager_(NULL) { }
    FocusableContainer(const Rect& rect, ContainerFocusManaging& focusManager): Focusable(), Container(rect), focusManager_(&focusManager) { }
    FocusableContainer& operator=(const FocusableContainer& other) { 
        if (&other != this) {
            focusManager_ = other.focusManager_;
        }
        return *this;
    }
    virtual ~FocusableContainer() {
        delete focusManager_;
    }

    void addWidget(Widget& widget);

    // from Focusable, which is just an interface
    virtual bool receiveKey(int ch) { return focusManager_->receiveKey(ch); }
    virtual bool isFocused() const { return focusManager_->isFocused(); }
    virtual void focus() const { return focusManager_->focus(); }
    virtual void deFocus() const { return focusManager_->deFocus(); }
    virtual const FocusManaging& getFocusManager() const;
    void focusFirst() const { focusManager_->focusFirst(); }
    void focusNext()const { focusManager_->focusNext(); }
    void focusPrev()const { focusManager_->focusPrev(); }
    void focusThis(const FocusableWidget *widget) const { focusManager_->focusThis(widget); }
    void focusThis(const unsigned int index) const { focusManager_->focusThis(index); }

protected:
    FocusableContainer(): Container() {}
    ContainerFocusManaging *focusManager_;
private:
};

}
#endif
