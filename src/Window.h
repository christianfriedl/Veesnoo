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


#ifndef NV_WINDOW_H
#define NV_WINDOW_H

#include <memory>
#include "FocusableContainer.h"

namespace veesnoo {

class Window : public FocusableContainer {
public:
    Window(const Rect& rect, const std::string title = "");
    static std::shared_ptr<Window> create(const Rect& rect, const std::string title = "") { return std::make_shared<Window>(rect, title); }
    void addContent() override;
    bool receiveKey(int ch) override { LOGMETHOD("%i", ch); return FocusableContainer::receiveKey(ch); } // just for debug
    void setTitle(const std::string title);

private:
    std::string title_;
};

}

#endif
