#ifndef NV_FOCUSABLE_WIDGET_H
#define NV_FOCUSABLE_WIDGET_H

#include "Focusable.h"
#include "SingleFocusManager.h"

namespace nv {

class FocusableWidget: public Focusable, public Widget {
public:
    FocusableWidget(const Rect& rect): Focusable(), Widget(rect), focusManager_(new SingleFocusManager(*this)) { }
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
    virtual bool isFocused() const { return focusManager_->isFocused(); }
    virtual void focus() const { return focusManager_->focus(); }
    virtual void deFocus() const { return focusManager_->deFocus(); }
    virtual const FocusManaging& getFocusManager() const;

protected:
    FocusableWidget(): Widget() {}
    FocusManaging *focusManager_;
private:
};

}
#endif
