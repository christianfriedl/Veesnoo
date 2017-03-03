#include "FocusableWidget.h"
#include "FocusableContainer.h"

namespace nv {
    FocusableContainer::FocusableContainer(const Rect& rect): 
        Focusable(), Container(rect), focusManager_(new ContainerFocusManager(this)) { } 

    FocusableContainer::~FocusableContainer() { 
        delete focusManager_; 
    }

    bool 
    FocusableContainer::receiveKey(int ch) { 
        Logger::get().log("FocusableContainer::receiveKey @ %lld", this);
        return focusManager_->receiveKey(ch); 
    }

    void 
    FocusableContainer::subWidgetHasFocused(std::shared_ptr<Focusable>& widget) {
        focusManager_->subWidgetHasFocused(widget);
    }
}
