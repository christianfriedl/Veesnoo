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


#include "Label.h"

namespace veesnoo {

    Label::Label(const std::string& text, const int x, const int y): Widget(Rect(x, y, text.size(), 1)), text_(text) { 
        LOGMETHOD("%s %s", toString().c_str(), text_.c_str()); 
    }

    std::shared_ptr<Label> Label::create(const std::string& text, const int x, const int y) {
        return std::make_shared<Label>(text, x, y);
    }

    void Label::setText(const std::string& text) {
        text_ = text;
        resize(text_.length(), 1);
    }
    void Label::addContent() {
        LOGMETHODONLY();
        startColorAttribute(getContentColorAttribute());
        addString(text_, 0, 0);
        endColorAttribute(getContentColorAttribute());
    }

}
