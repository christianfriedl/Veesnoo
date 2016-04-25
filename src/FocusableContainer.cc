#include "FocusableWidget.h"
#include "FocusableContainer.h"

namespace nv {

bool FocusableContainer::receiveKey(int ch) { return focusManager_->receiveKey(ch); }
}
