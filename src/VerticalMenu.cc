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


#include "Logger.h"
#include "VerticalMenu.h"
#include "ContainerFocusManager.h"

namespace veesnoo {

    VerticalMenu::VerticalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)) { 
        LOGMETHODONLY();
    }

    const std::shared_ptr<VerticalMenu>
    VerticalMenu::create(const int x, const int y) {
        return std::make_shared<VerticalMenu>(x, y);
    }

    void VerticalMenu::addWidget(const std::shared_ptr<Widget>& widget) {
        FocusableContainer::addWidget(widget);
        layout();
    }

    void VerticalMenu::layout() {
        int width = 0, height = 0;

        for ( auto widget: subWidgets_ ) {
            widget->move(0, height);
            width = std::max(width, widget->getRect().getWidth());
            ++height;
        }
        resize(width, height);
    }

}
