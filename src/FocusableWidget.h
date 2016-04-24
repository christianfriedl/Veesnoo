#ifndef NV_FOCUSABLE_WIDGET_H
#define NV_FOCUSABLE_WIDGET_H

#include "Focusable.h"
#include "SingleFocusManager.h"

namespace nv {

class FocusableWidget: public Focusable, public Widget {
public:
    FocusableWidget(const Rect& rect): Focusable(), Widget(rect) { }

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
