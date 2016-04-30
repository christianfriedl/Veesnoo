#ifndef NV_FOCUS_MANAGING_H
#define NV_FOCUS_MANAGING_H

#include "Widget.h"

namespace nv {

class FocusManaging {
public:
    virtual bool receiveKey(int ch) = 0;
    virtual void focus() = 0;
    virtual void deFocus() = 0;
    virtual bool isFocused() = 0;

};

}

#endif
