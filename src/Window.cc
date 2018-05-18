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
#include "ContainerFocusManager.h"
#include "Widget.h"
#include "Window.h"

namespace veesnoo {

    Window::Window(const Rect& rect, const std::string title) : FocusableContainer(rect), title_(title) {
        colorTag_ = "Window";
        isFocusStealing_ = true;
        contentRect_ = Rect(1, 1, rect.getWidth() - 2, rect.getHeight() - 2);
    }

    void Window::setTitle(const std::string title) {
        title_ = title;
    }

    void Window::addContent() {
        LOGMETHODONLY();
        startColorAttribute(getContentColorAttribute());
        LOGMETHOD("content colattr fg %i, bg %i", getContentColorAttribute().getFg(), getContentColorAttribute().getBg());
        LOGMETHOD("border colattr fg %i, bg %i", getBorderColorAttribute().getFg(), getBorderColorAttribute().getBg());
        cursesWindow_->addBorder();
        cursesWindow_->addString(title_, ( rect_.getWidth() - title_.size() ) / 2, 0);
        endColorAttribute(getContentColorAttribute());
    }


}
