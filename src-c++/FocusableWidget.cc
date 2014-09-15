#include "FocusableWidget.h"

namespace nv {

inline const FocusManaging& FocusableWidget::getFocusManager() { return *focusManager_; }

}
