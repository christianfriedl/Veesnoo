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


#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Widget.h"
#// include "KeyReceiving.h"
#include "Button.h"

namespace veesnoo {

    Button::Button(const std::string& text, int x, int y): FocusableWidget(Rect(x, y, text.size() + 4, 1)), text_(text), state_(ButtonState_normal) {
    }

    std::shared_ptr<Button> Button::create(const std::string& text, int x, int y) {
        return std::make_shared<Button>(text, x, y);
    }

    void Button::addContent() {
        LOGMETHODONLY();
        startColorAttribute(getContentColorAttribute(isFocused() || state_ == ButtonState_pushed));
        std::stringstream s; 
        s << "[ " << text_ << " ]";
        addString(s.str(), 0, 0);
        endColorAttribute(getContentColorAttribute(isFocused() || state_ == ButtonState_pushed));
    }

    bool Button::push() {
        state_ = ButtonState_pushed;
        // TODO do stuff
        refresh();
        state_ = ButtonState_normal;
        refresh();
        {
            auto ev(std::make_shared<BasicEvent>(shared_from_this()));
            onAfterPush.emit(ev);
        }
        return true;
    }

    bool Button::receiveKey(int ch) {
        LOGMETHOD("%i", ch);
        if (ch == ' ' || ch == 13) {
            return push();
        }
        return false;
    }

}

