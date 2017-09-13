#ifndef NV_RADIO_BUTTON_H
#define NV_RADIO_BUTTON_H

#include <string>
#include "FocusableWidget.h"
#include "ChangeEvent.h"

namespace nv {

enum class RadioButtonState { unchecked, checked };

class RadioButton: public FocusableWidget { // , public KeyReceiving {
public:
    RadioButton(int x, int y, const std::string& value);
    void setFrame(const std::string& frame);
    bool receiveKey(int ch) override;
    void refresh() override;
    bool push(); 
    bool isChecked();
    void setChecked(const bool checked);
    sigc::signal<void, const std::shared_ptr<ChangeEvent>&> onAfterChange;

private:
    RadioButtonState state_;
    std::string frame_;
    const std::string value_;
};

}

#endif
