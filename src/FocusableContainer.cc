#include "FocusableWidget.h"
#include "FocusableContainer.h"

namespace nv {
    FocusableContainer::FocusableContainer(const Rect& rect): 
        Focusable(), Container(rect), focusManager_(new ContainerFocusManager(this)) { } 

    const std::shared_ptr<FocusableContainer> FocusableContainer::create(const Rect& rect) {
        return std::make_shared<FocusableContainer>(rect);
    }

    FocusableContainer::~FocusableContainer() { 
        delete focusManager_; 
    }

    bool 
    FocusableContainer::receiveKey(int ch) { 
        Logger::get().log("FocusableContainer(%llx)::receiveKey(%i)", this, ch);
        return focusManager_->receiveKey(ch); 
    }

    void 
    FocusableContainer::subWidgetHasFocused(std::shared_ptr<Focusable>& widget) {
        focusManager_->subWidgetHasFocused(widget);
    }

    void
    FocusableContainer::refresh() {
        Container::refresh();
        auto focusedFocusable = focusManager_->getFocusedWidget();
        if ( !focusedFocusable )
            return;
        auto focusedWidget = std::dynamic_pointer_cast<FocusableWidget>(focusedFocusable);
        if ( !focusedWidget )
            return;
        focusedWidget->refresh();
    }
}
