#ifndef NV_FOCUSABLE_H
#define NV_FOCUSABLE_H

#include "FocusManaging.h"

namespace nv {

class Focusable {

public:
    virtual bool receiveKey(int ch) = 0;
    virtual bool isFocused() const = 0;
    virtual void focus() const = 0;
    virtual void deFocus() const = 0;
    virtual const FocusManaging& getFocusManager() const = 0;
};

}

#endif
