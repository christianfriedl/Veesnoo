#ifndef NV_FOCUSABLE_WIDGET_H
#define NV_FOCUSABLE_WIDGET_H

#include "Focusable.h"
#include "Widget.h"

namespace nv {

    class FocusableWidget: public Focusable, public Widget {
        public:
            explicit FocusableWidget(const Rect& rect): Focusable(), Widget(rect), isFocused_(false) { }
            virtual ~FocusableWidget() {}

            virtual bool receiveKey(int ch) override;
            virtual bool isFocused() const override;
            virtual void focus() override;
            virtual void blur() override;
            const std::string toString() const override;

        private:
            bool isFocused_;
    };

}
#endif
