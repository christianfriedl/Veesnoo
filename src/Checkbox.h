#ifndef NV_CHECKBOX_H
#define NV_CHECKBOX_H

#include <string>
#include "FocusableWidget.h"

namespace nv {

typedef enum { CheckboxState_unchecked, CheckboxState_checked } CheckboxState;

class Checkbox: public FocusableWidget { // , public KeyReceiving {
public:
    Checkbox(int x, int y);
    // no need for ~Checkbox(); !, the parent does that
    void setFrame(const std::string& frame);
    void refresh();
    bool push(); 
    bool isChecked();
    bool receiveKey(int ch);

private:
    CheckboxState state_;
    std::string frame_;
};

}

#endif
