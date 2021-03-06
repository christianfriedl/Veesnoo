/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Veesnoo is free software; you can redistribute it and/or modify
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


#ifndef NV_FOCUSABLE_WIDGET_H
#define NV_FOCUSABLE_WIDGET_H

#include "Focusable.h"
#include "Widget.h"

namespace veesnoo {

    class FocusableWidget: public Focusable, public Widget {
        public:
            explicit FocusableWidget(const Rect& rect);
            virtual ~FocusableWidget() {}

            bool receiveKey(int ch) override;
            bool isFocused() const override;
            void focus() override;
            void blur() override;

            virtual const ColorAttribute& getContentColorAttribute() override;
            virtual const ColorAttribute& getContentColorAttribute(bool focused);
            virtual const ColorAttribute& getBorderColorAttribute() override;
            virtual const ColorAttribute& getBorderColorAttribute(bool focused);

            const std::string toString() const override;

        protected:
            FocusableWidget();

            bool isFocused_;
    };

}
#endif
