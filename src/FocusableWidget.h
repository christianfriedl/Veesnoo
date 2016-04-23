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


    virtual bool receiveKey(int ch);
    virtual bool isFocused() const;
    virtual void focus();
    virtual void deFocus();

protected:
    FocusableWidget(): Widget() {}

private:
    bool isFocused_;
};

}
#endif
