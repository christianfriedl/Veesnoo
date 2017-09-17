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


#ifndef NV_POPUP_MENU_H
#define NV_POPUP_MENU_H

#include "MenuItem.h"
#include "PopupWindow.h"

class VerticalMenu;
namespace nv {
    class PopupMenu : public PopupWindow {
        public:
            PopupMenu(const int x, const int y); // TODO this is public... figure out how to make it callable ONLY from create()
            static std::shared_ptr<PopupMenu> create(const int x, const int y);
            const std::shared_ptr<MenuItem>& addItem(const std::shared_ptr<MenuItem>& mi);
            const std::shared_ptr<MenuItem>& addItem(const std::string& name);
            void setMenu(const std::shared_ptr<VerticalMenu>& menu);
            void addWidget(const std::shared_ptr<Widget>& widget) override;
            void layout();
            virtual bool receiveKey(int ch) override { LOGMETHOD("%i", ch); return PopupWindow::receiveKey(ch); } // just for debug

        private:
            std::shared_ptr<VerticalMenu> menu_;

    };
}

#endif
