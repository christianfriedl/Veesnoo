#ifndef NV_FOCUSABLE_CONTAINER_H
#define NV_FOCUSABLE_CONTAINER_H

#include "Focusable.h"
#include "Container.h"

namespace nv {

class FocusableContainer: public Focusable, public Container {
public:
    FocusableContainer(const Rect& rect): Focusable(), Container(rect), focusManager_(NULL) { }
    FocusableContainer(const Rect& rect, FocusManaging& focusManager): Focusable(), Container(rect), focusManager_(&focusManager) { }
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
    virtual bool isFocused() { return focusManager_->isFocused(); }
    virtual void focus() { return focusManager_->focus(); }
    virtual void deFocus() { return focusManager_->deFocus(); }
    virtual const FocusManaging& getFocusManager();

protected:
    FocusableContainer(): Container() {}
    FocusManaging *focusManager_;
private:
};

}
#endif
