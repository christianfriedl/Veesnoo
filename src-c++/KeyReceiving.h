#ifndef NV_KEY_RECEIVING_H
#define NV_KEY_RECEIVING_H

class KeyReceiving {

    virtual bool receiveKey(int ch) = 0;
    virtual bool isFocused() = 0;
    virtual void focus() = 0;
    virtual void deFocus() = 0;

};

#endif
