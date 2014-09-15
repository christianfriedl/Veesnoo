#ifndef NV_SINGLE_FOCUS_MANAGER_H
#define NV_SINGLE_FOCUS_MANAGER_H

#include "FocusManaging.h"
#include "Widget.h"

namespace nv {

class SingleFocusManager: public FocusManaging {
public:
    SingleFocusManager(const Widget& widget): widget_(&widget) {}
    virtual ~SingleFocusManager() {}
    virtual bool receiveKey(int ch);
    virtual void focus();
    virtual void deFocus();
    virtual void setWidget(const Widget& widget) { widget_ = &widget; }
    virtual bool isFocused() { return isFocused_; }
private:
    bool isFocused_;
    const Widget *widget_;
};

}

#endif
