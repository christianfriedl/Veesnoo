#ifndef NV_FOCUSABLE_H
#define NV_FOCUSABLE_H

namespace nv {

class Focusable {

public:
    virtual bool receiveKey(int ch) = 0;
    virtual bool isFocused() const = 0;
    virtual void focus() = 0;
    virtual void deFocus() = 0;
};

}

#endif
