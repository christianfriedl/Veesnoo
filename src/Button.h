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


#ifndef NV_BUTTON_H
#define NV_BUTTON_H

#include <string>
#include "FocusableWidget.h"
#include "BasicEvent.h"

namespace nv {

    typedef enum { ButtonState_normal, ButtonState_pushed } ButtonState;

    class Button: public FocusableWidget { // , public KeyReceiving {
        public:
            Button(const std::string& text, int x, int y);
            void refresh() override;
            bool push(); 
            bool receiveKey(int ch) override;
            sigc::signal<void, const std::shared_ptr<BasicEvent>&> onAfterPush;

        private:
            std::string text_;
            ButtonState state_;

    };

}

#endif
