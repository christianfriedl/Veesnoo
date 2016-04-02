#include "FocusableWidget.h"

namespace nv {

inline 
const FocusManaging& FocusableWidget::getFocusManager() const { return *focusManager_; }

}
