#ifndef NV_FOCUS_MANAGING_H
#define NV_FOCUS_MANAGING_H

namespace nv {

class FocusManaging {
public:
    virtual ~FocusManaging() {}

    virtual bool receiveKey(int ch) = 0;
    virtual void focus() = 0;
    virtual void blur() = 0;
    virtual bool isFocused() const = 0;

};

}

#endif
