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


/*
 * have only one container, so we can easily debug memory management
 */

#include <memory>
#include "Widget.h"
#include "Container.h"
#include "Logger.h"

using namespace veesnoo;

int main() {
     Container c(Rect(0, 0, 20, 1));
     auto w(std::make_shared<Widget>(Rect(0, 0, 1, 1)));
     c.addWidget(w);
    // we don't even wait for getch()
}
