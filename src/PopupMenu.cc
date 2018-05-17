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


#include "VerticalMenu.h"
#include "PopupMenu.h"
#include"Logger.h"

namespace veesnoo {

    PopupMenu::PopupMenu(const int x, const int y) : PopupWindow(Rect(x, y, 1, 1)), menu_(std::make_shared<VerticalMenu>(0, 0)) {
		LOGMETHOD("new PopupMenu %s", toString().c_str());
    }

    std::shared_ptr<PopupMenu> PopupMenu::create(const int x, const int y) {
        auto widget(std::make_shared<PopupMenu>(x, y));
        widget->addWidget(widget->menu_);
        return widget;
    }

    // TODO remove old menu first
    void PopupMenu::setMenu(const std::shared_ptr<VerticalMenu>& menu) {
        menu_ = menu;
    }

    void PopupMenu::addWidget(const std::shared_ptr<Widget>& widget) {
        Window::addWidget(widget);
        layout();
    }


    const std::shared_ptr<MenuItem>& 
    PopupMenu::addItem(const std::shared_ptr<MenuItem>& mi) {
        menu_->addWidget(mi);
        layout();
        return mi;
    }

    const std::shared_ptr<MenuItem>& 
    PopupMenu::addItem(const std::string& name) {
        auto mi = std::make_shared<MenuItem>(name);
        return addItem(mi);
    }

    void 
    PopupMenu::layout() {
        LOGMETHODONLY();
        resize(menu_->getRect().getWidth() + 2, menu_->getRect().getHeight() + 2);
    }

}
