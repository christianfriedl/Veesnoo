/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Mapitor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */


#ifndef NV_FOCUSABLE_CONTAINER_H
#define NV_FOCUSABLE_CONTAINER_H

#include <memory>
#include "Focusable.h"
#include "Focusable.h"
#include "Container.h"
#include "ContainerFocusManager.h"

namespace veesnoo {
    class FocusableContainer: public Focusable, public Container {
        public:
            explicit FocusableContainer(const Rect& rect);
            static const std::shared_ptr<FocusableContainer> create(const Rect& rect);
            virtual ~FocusableContainer();

            bool getIsFocusStealing();
            void setIsFocusStealing(bool isFocusStealing);

            bool receiveKey(int ch) override;
            void refresh() override;

            /**
             * somebody requests the focus for the given widget from us
             */
            void requestFocus(std::shared_ptr<Focusable>& widget);
            const std::shared_ptr<FocusableContainer> findRootFocusable();

            // delegates to the focusManager_

            bool isFocused() const override;
            void focus() override;
            void blur() override;

            void focusFirst();
            void focusNext();
            void focusPrev();
            void focusThis(std::shared_ptr<Focusable>& widget);
            std::shared_ptr<Focusable> getFocusedWidget();

        protected:
            ContainerFocusManager *focusManager_;
            bool isFocusStealing_;
        private:
    };

}
#endif
