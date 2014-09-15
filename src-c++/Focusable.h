#ifndef NV_FOCUSABLE_H
#define NV_FOCUSABLE_H

#include "FocusManaging.h"

namespace nv {

class Focusable {

public:
    virtual bool receiveKey(int ch) = 0;
    virtual bool isFocused() = 0;
    virtual void focus() = 0;
    virtual void deFocus() = 0;
    virtual const FocusManaging& getFocusManager() = 0;
};

}

#endif
