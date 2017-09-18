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
#include <string.h>
#include "Widget.h"
#include "CheckBox.h"

namespace veesnoo {

    CheckBox::CheckBox(int x, int y): FocusableWidget(Rect(x, y, 3, 1)), state_(CheckboxState_unchecked), frame_("[]") {
        LOGMETHODONLY();
    }

    void CheckBox::setFrame(const std::string& frame) {
        frame_ = frame;
    }

    void CheckBox::addContent() {
        LOGMETHODONLY();
        if ( isFocused() )
            cursesWindow_->attrOn(A_REVERSE);
        char c = (state_ == CheckboxState_checked ? 'x' : ' ');
        std::stringstream s; 
        s << frame_[0] << c << frame_[1];
        addString(s.str(), 0, 0);
        if ( isFocused() )
            cursesWindow_->attrOff(A_REVERSE);
    }

    bool CheckBox::push() {
        state_ = (state_ == CheckboxState_checked ? CheckboxState_unchecked : CheckboxState_checked);
        // TODO do stuff
        refresh();
        return true;
    }

    bool CheckBox::isChecked() {
        return state_ == CheckboxState_checked;
    }

    bool CheckBox::receiveKey(int ch) {
        LOGMETHOD("%i, isFocused: %i", ch, isFocused());
        if (ch == ' ' || ch == 13) {
            return push();
        }
        return false;
    }

}
