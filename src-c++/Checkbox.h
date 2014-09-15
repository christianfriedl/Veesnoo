#ifndef NV_CHECKBOX_H
#define NV_CHECKBOX_H

#include <string>
#include "FocusableWidget.h"

namespace nv {

typedef enum { CheckboxState_unchecked, CheckboxState_checked } CheckboxState;

class Checkbox: public FocusableWidget { // , public KeyReceiving {
public:
    Checkbox(const std::string& text, int x, int y);
    void refresh();
    bool push(); 
    bool isChecked();
    bool receiveKey(int ch);

private:
    std::string text_;
    CheckboxState state_;
};

}

#endif
