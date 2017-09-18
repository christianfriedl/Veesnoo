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


#include "MainWindow.h"
#include "MainWindowFocusManager.h"

namespace veesnoo {
    MainWindow::MainWindow(const Rect& rect, const std::string title) : Window(rect, title) {
        Logger::get().log("new MainWindow @ %ld %s", toString().c_str());
        delete focusManager_;
        focusManager_ = new MainWindowFocusManager(this);
    }
}
