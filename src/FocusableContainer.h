#ifndef NV_FOCUSABLE_CONTAINER_H
#define NV_FOCUSABLE_CONTAINER_H

#include <memory>
#include "Focusable.h"
#include "Focusable.h"
#include "Container.h"
#include "ContainerFocusManager.h"

namespace nv {
    class FocusableContainer: public Focusable, public Container {
        public:
            explicit FocusableContainer(const Rect& rect);
            static const std::shared_ptr<FocusableContainer> create(const Rect& rect);
            virtual ~FocusableContainer();

            virtual bool receiveKey(int ch);
            virtual void refresh();

            virtual bool isFocused() const { return focusManager_->isFocused(); }
            virtual void focus() { focusManager_->focus(); }
            virtual void deFocus() { focusManager_->deFocus(); }

            void focusFirst() { focusManager_->focusFirst(); }
            void focusNext() { focusManager_->focusNext(); }
            void focusPrev() { focusManager_->focusPrev(); }
            void focusThis(std::shared_ptr<Focusable>& widget) { focusManager_->focusThis(widget); }

            void subWidgetHasFocused(std::shared_ptr<Focusable>& widget);

        protected:
            ContainerFocusManager *focusManager_;
        private:
    };

}
#endif
