#ifndef NV_FOCUSABLE_WIDGET_H
#define NV_FOCUSABLE_WIDGET_H

#include "Focusable.h"

namespace nv {

class FocusableWidget: public Focusable, public Widget {
public:
    FocusableWidget(const Rect& rect): Focusable(), Widget(rect), focusManager_(NULL) { }
    FocusableWidget(const Rect& rect, FocusManaging& focusManager): Focusable(), Widget(rect), focusManager_(&focusManager) { }
    FocusableWidget& operator=(const FocusableWidget& other) { 
        if (&other != this) {
            focusManager_ = other.focusManager_;
        }
        return *this;
    }
    virtual ~FocusableWidget() {
        delete focusManager_;
    }


    virtual bool receiveKey(int ch) { return focusManager_->receiveKey(ch); }
    virtual bool isFocused() { return focusManager_->isFocused(); }
    virtual void focus() { return focusManager_->focus(); }
    virtual void deFocus() { return focusManager_->deFocus(); }
    virtual const FocusManaging& getFocusManager();

protected:
    FocusManaging *focusManager_;
private:
    FocusableWidget() {}
};

}
#endif