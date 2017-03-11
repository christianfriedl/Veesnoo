#ifndef NV_CHECKBOX_H
#define NV_CHECKBOX_H

#include <string>
#include "FocusableWidget.h"

namespace nv {

typedef enum class { unchecked, checked } RadioButtonState;

class RadioButton: public FocusableWidget { // , public KeyReceiving {
public:
    RadioButton(int x, int y, const std::string& value);
    void setFrame(const std::string& frame);
    void refresh();
    bool push(); 
    bool isChecked();
    bool receiveKey(int ch);

private:
    RadioButtonState state_;
    std::string frame_;
    const std::string value_;
};

}

#endif
