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


#include "Logger.h"
#include "HorizontalMenu.h"
#include "ContainerFocusManager.h"

namespace veesnoo {

HorizontalMenu::HorizontalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)) { } 

void HorizontalMenu::addWidget(const std::shared_ptr<Widget>& widget) {
    FocusableContainer::addWidget(widget);
    layout();
}

void HorizontalMenu::layout() {
    Logger::get().log("HorizontalMenu @%llx layouting", this);
    int width = 0, i = 0;

    for ( auto widget: subWidgets_ ) {
        if ( i != 0 )
            width += 1;
        ++i;
        widget->move(width, 0);
        width += widget->getRect().getWidth();
    Logger::get().log("HorizontalMenu width is %i, i is %i", width, i);
    }
    rect_.resize(width, rect_.getHeight());
    Logger::get().log("HorizontalMenu layouting done");
}

}
