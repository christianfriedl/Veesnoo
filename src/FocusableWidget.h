#ifndef NV_FOCUSABLE_WIDGET_H
#define NV_FOCUSABLE_WIDGET_H

#include "Focusable.h"
#include "Widget.h"

namespace nv {

    class FocusableWidget: public Focusable, public Widget {
        public:
            explicit FocusableWidget(const Rect& rect): Focusable(), Widget(rect), isFocused_(false) { }
            virtual ~FocusableWidget() {}

            virtual bool receiveKey(int ch);
            virtual bool isFocused() const;
            virtual void focus();
            virtual void deFocus();
            virtual void blur();
            const std::string toString() const;

        private:
            bool isFocused_;
    };

}
#endif
