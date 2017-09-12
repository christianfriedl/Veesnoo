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

            virtual bool receiveKey(int ch) override;
            virtual void refresh() override;

            /**
             * somebody requests the focus for the given widget from us
             */
            void requestFocus(std::shared_ptr<Focusable>& widget);
            const std::shared_ptr<FocusableContainer> findRootFocusable();

            // delegates to the focusManager_

            virtual bool isFocused() const override;
            virtual void focus() override;
            virtual void blur() override;

            void focusFirst();
            void focusNext();
            void focusPrev();
            void focusThis(std::shared_ptr<Focusable>& widget);
            std::shared_ptr<Focusable> getFocusedWidget();

        protected:
            ContainerFocusManager *focusManager_;
        private:
    };

}
#endif
