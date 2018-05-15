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


#ifndef NV_LABEL_H
#define NV_LABEL_H

#include <string>
#include <iostream>
#include "Rect.h"
#include "CursesWindow.h"
#include "Widget.h"

namespace veesnoo {

class Label: public Widget {
public:
    Label(const std::string& text, const int x, const int y);

    static std::shared_ptr<Label> create(const std::string& text, const int x, const int y);

    void setText(const std::string& text);
    void addContent() override;
private:
    std::string text_;
};

}

#endif
