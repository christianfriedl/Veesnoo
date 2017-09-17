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
#include "ContainerFocusManager.h"
#include "Widget.h"
#include "Window.h"

namespace nv {

    Window::Window(const Rect& rect, const std::string title) : FocusableContainer(rect), title_(title) {
        isFocusStealing_ = true;
        contentRect_ = Rect(1, 1, rect.getWidth() - 2, rect.getHeight() - 2);
        Logger::get().log("new Window @ %ld %s", toString().c_str());
    }

    void Window::setTitle(const std::string title) {
        title_ = title;
    }

    void Window::addContent() {
        LOGMETHODONLY();
        startColorAttribute(getPrimaryColorAttribute());
        cursesWindow_->addBorder();
        cursesWindow_->addString(title_, ( rect_.getWidth() - title_.size() ) / 2, 0);
        endColorAttribute(getPrimaryColorAttribute());
    }


}
