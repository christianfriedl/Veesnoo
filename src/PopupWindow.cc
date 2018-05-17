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
#include "PopupWindow.h"

namespace veesnoo {

    PopupWindow::PopupWindow(const Rect& rect, const std::string title): Window(rect, title), FocusStealing() {
        LOGMETHODONLY();
    }

    PopupWindow::~PopupWindow() {
        LOGMETHODONLY();
    }

    const std::shared_ptr<Focusable>& PopupWindow::getPreviouslyFocusedWidget() const {
        return previouslyFocusedWidget_;
    }

    bool PopupWindow::open() {
        LOGMETHODONLY();
        auto root = findRootFocusable();
        previouslyFocusedWidget_ = root->getFocusedWidget();
        LOGMETHOD("setting previouslyFocusedWidget_ = %llx", previouslyFocusedWidget_.get());
        show();
        focus();
        refresh();
        return true;
    }

    /**
     * we stole the focus on opening, so
     * we need to give it back now
     */
    bool PopupWindow::close() {
        LOGMETHODONLY();
        hide();
        if ( previouslyFocusedWidget_.use_count() == 0 ) {
            return false;
        }

        blur();

        previouslyFocusedWidget_->focus();
        return true;
    }
}
