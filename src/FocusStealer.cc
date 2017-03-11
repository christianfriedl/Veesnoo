#include "Logger.h"
#include "Focusable.h"
#include "FocusStealer.h"

namespace nv {

    const std::shared_ptr<Focusable>& FocusStealer::getPreviouslyFocusedWidget() const {
        return previouslyFocusedWidget_;
    }

    /**
     * we stole the focus on opening, so
     * we need to give it back now
     */
    bool FocusStealer::close() {
        Logger::get().log("FocusStealer(%llx)::close(), previouslyFocusedWidget_ = %llx", this, previouslyFocusedWidget_.get());
        if ( previouslyFocusedWidget_.use_count() == 0 )
            throw std::runtime_error("no previously focused widget found");
        previouslyFocusedWidget_->focus();
        return true;
    }
}
