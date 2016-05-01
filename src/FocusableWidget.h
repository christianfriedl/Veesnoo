#ifndef NV_FOCUSABLE_WIDGET_H
#define NV_FOCUSABLE_WIDGET_H

#include "Focusable.h"
#include "Widget.h"

namespace nv {

class FocusableWidget: public Focusable, public Widget {
public:
    explicit FocusableWidget(const Rect& rect): Focusable(), Widget(rect) { }
    virtual ~FocusableWidget() {}

    virtual bool receiveKey(int ch);
    virtual bool isFocused() const;
    virtual void focus();
    virtual void deFocus();


protected:

private:
    bool isFocused_;
};

}
#endif
