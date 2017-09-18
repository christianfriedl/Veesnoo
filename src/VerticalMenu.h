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


#ifndef NV_VERTICAL_MENU_H
#define NV_VERTICAL_MENU_H

#include "MenuItem.h"
#include "FocusableContainer.h"

namespace nv {

    class VerticalMenu: public FocusableContainer {
    public:
        VerticalMenu(const int x, const int y);
        static const std::shared_ptr<VerticalMenu> create(const int x, const int y);
        virtual ~VerticalMenu() {}
        void addWidget(const std::shared_ptr<Widget>& widget) override;
        bool receiveKey(int ch) override { LOGMETHOD("%i", ch); return FocusableContainer::receiveKey(ch); } // just for debug

    private:
        void layout(); // not virtual, because each widget will ahve to know on its own how to do this
    };

}

#endif
