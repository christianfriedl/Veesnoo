#ifndef NV_CHECKBOX_H
#define NV_CHECKBOX_H

#include <string>
#include "FocusableWidget.h"

namespace nv {

typedef enum { CheckboxState_unchecked, CheckboxState_checked } CheckboxState;

class CheckBox: public FocusableWidget {
public:
    CheckBox(int x, int y);
    void setFrame(const std::string& frame);
    void addContent() override;
    bool push(); 
    bool isChecked();
    bool receiveKey(int ch) override;

private:
    CheckboxState state_;
    std::string frame_;
};

}

#endif
