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


namespace veesnoo {

MenuItem::MenuItem(const std::string& text, const int x, const int y) : FocusableWidget(Rect(x, y, text.size(), 1)), text_{text} {
    LOGMETHOD("MenuItem::MenuItem(%s, %i, %i)", text.c_str(), x, y);
}

MenuItem::MenuItem(const std::string& text, const Rect& rect) : FocusableWidget{Rect(rect.getX(), rect.getY(), rect.getWidth(), 1)}, text_{text}
{
}

MenuItem::MenuItem(const std::string& text) : FocusableWidget(Rect(0, 0, text.size(), 1)), text_{text} {
    LOGMETHOD("MenuItem::MenuItem(%s)", text.c_str());
}

std::shared_ptr<MenuItem> MenuItem::create(const std::string& text, const int x, const int y) {
    return std::make_shared<MenuItem>(text, x, y);
}

std::shared_ptr<MenuItem> MenuItem::create(const std::string& text) {
    return std::make_shared<MenuItem>(text);
}

std::shared_ptr<MenuItem> MenuItem::create(const std::string& text, const Rect& rect) {
    return std::make_shared<MenuItem>(text, rect);
}

void MenuItem::addContent() {
    LOGMETHODONLY();
    char fillChar = ' ';

    startColorAttribute(getContentColorAttribute());

    addString(text_, 0, 0); 

    for ( int i = std::min(rect_.getWidth(), (int)text_.length()); i < rect_.getWidth(); ++i )
        addCh(fillChar, i, 0);

    endColorAttribute(getContentColorAttribute());
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
