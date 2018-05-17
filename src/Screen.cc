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


#include <string.h>
#include "Screen.h"

namespace veesnoo {
    std::shared_ptr<Screen> Screen::create() {
        auto sc = std::make_shared<Screen>();
        return sc;
    }

    Screen::Screen(): FocusableContainer(Rect(0, 0, 1, 1)) {
        LOGMETHODONLY();
        rect_ = CursesManager::get().getMaxScreenRect(); // TODO why can't I just initialize from this via copy-constr?
        contentRect_ = rect_;
    }

    bool Screen::receiveKey(int ch) {
        const char * const name = CursesManager::get().getKeyName(ch);
        if ( strncmp(name, "^C", 2) == 0 )
            return false;
        FocusableContainer::receiveKey(ch); // we ignore the rv here
        return true;
    }
}
