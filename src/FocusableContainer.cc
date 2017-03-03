#include "FocusableWidget.h"
#include "FocusableContainer.h"

namespace nv {
    bool FocusableContainer::receiveKey(int ch) { 
        Logger::get().log("FocusableContainer::receiveKey @ %lld", this);
        return focusManager_->receiveKey(ch); 
    }
}
