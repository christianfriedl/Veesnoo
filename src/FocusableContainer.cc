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
    FocusableContainer::requestFocus(std::shared_ptr<Focusable>& widget) {
        LOGMETHOD("%llx", widget.get());
        focusManager_->requestFocus(widget);
    }

    void
    FocusableContainer::refresh() {
        Logger::get().log("FocusableContainer(%llx)::refresh()", this);
        if ( !getIsVisibleBubbling() )
            return;
        Container::refresh();
        auto focusedFocusable = focusManager_->getFocusedWidget();
        if ( !focusedFocusable )
            return;
        auto focusedWidget = std::dynamic_pointer_cast<FocusableWidget>(focusedFocusable);
        if ( !focusedWidget )
            return;
        Logger::get().log("FocusableContainer(%llx)::refresh() will refresh focusedWidget %llx", this, focusedWidget.get());
        if ( focusedWidget->getIsVisible() )
            focusedWidget->refresh();
    }

    const std::shared_ptr<FocusableContainer> FocusableContainer::findRootFocusable() {
        if ( parent_.use_count() == 0 ) {
            auto justForLogging = std::dynamic_pointer_cast<FocusableContainer>(shared_from_this());
            LOG("returning %llx", justForLogging.get());
            return justForLogging;
        }
        auto p = parent_.lock();
        if ( !p ) throw Exception("cannot lock parent_");
        auto pp = std::dynamic_pointer_cast<FocusableContainer>(p);
        if ( !pp ) throw Exception("cannot transform parent_");
        return pp->findRootFocusable();
    }

}
