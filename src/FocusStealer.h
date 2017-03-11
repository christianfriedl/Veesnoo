#ifndef NV_FOCUS_STEALER_H
#define NV_FOCUS_STEALER_H

#include <memory>
#include "FocusStealing.h"

class Focusable;

namespace nv {
    /**
     * default implementation of a (popup) widget that will steal the focus
     * away from the currently focused widget
     */

    class FocusStealer: public FocusStealing {
        public:
            virtual ~FocusStealer() {}
            virtual bool close();
            virtual const std::shared_ptr<Focusable>& getPreviouslyFocusedWidget() const;
        private:
            std::shared_ptr<Focusable> previouslyFocusedWidget_;
    };
}

#endif
