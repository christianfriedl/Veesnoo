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


#include "NVBase.h"
#include "MenuItem.h"
#include "BasicEvent.h"


namespace nv {

MenuItem::MenuItem(const std::string& text, const int x, const int y) : FocusableWidget(Rect(x, y, text.size(), 1)), text_{text} {
    LOGMETHOD("MenuItem::MenuItem(%s, %i, %i)", text.c_str(), x, y);
}

MenuItem::MenuItem(const std::string& text) : FocusableWidget(Rect(0, 0, text.size(), 1)), text_{text} {
    LOGMETHOD("MenuItem::MenuItem(%s)", text.c_str());
}

void MenuItem::addContent() {
    LOGMETHODONLY();
    Logger::get().log("MenuItem(%llx)::addContent(), text: '%s', %s, isFocused=%i", this, text_.c_str(), toString().c_str(), isFocused());
    char fillChar = ' ';
    if ( isFocused() ) {
        Logger::get().log("is focused! ");
        cursesWindow_->attrOn(A_REVERSE);
    }

    addString(text_, 0, 0); 

    for ( int i = std::min(rect_.getWidth(), (int)text_.length()); i < rect_.getWidth(); ++i )
        addCh(fillChar, i, 0);

    if ( isFocused() )
        cursesWindow_->attrOff(A_REVERSE);
}

bool MenuItem::push() {
    auto ev(std::make_shared<BasicEvent>(shared_from_this()));
    onAfterPush.emit(ev);
    return true;
}

bool MenuItem::receiveKey(int ch) {
    LOGMETHOD("%i", ch);
    if (ch == Key_Enter || ch == ' ') {
        return push();
    } else
        return false;
}

const std::string& MenuItem::getText() {
    return text_;
}

}
