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


#ifndef NV_MENU_ITEM_H
#define NV_MENU_ITEM_H

#include "FocusableWidget.h"

namespace veesnoo {

typedef enum { MenuItemState_normal, MenuItemState_pushed } MenuItemState;

class BasicEvent;
class MenuItem: public FocusableWidget {
public:
    MenuItem(const std::string& text, const int x, const int y);
    MenuItem(const std::string& text);
    MenuItem(const std::string& text, const Rect& rect);
    static std::shared_ptr<MenuItem> create(const std::string& text, const int x, const int y);
    static std::shared_ptr<MenuItem> create(const std::string& text);
    static std::shared_ptr<MenuItem> create(const std::string& text, const Rect& rect);
    virtual ~MenuItem() {}
    void addContent() override;
    bool receiveKey(int ch) override;
    bool push();
    const std::string& getText();
    sigc::signal<void, const std::shared_ptr<BasicEvent>&> onAfterPush;

private:
    std::string text_;

};

}

#endif
