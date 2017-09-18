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


#include "MenuItem.h"
#include "VerticalMenu.h"
#include "MainLoop.h"

using namespace veesnoo;

int main() {
    auto m1 (std::make_shared<MenuItem>("menuitem1"));
    auto m2 (std::make_shared<MenuItem>("menuitem2"));
    auto m3 (std::make_shared<MenuItem>("menuitem3"));
    auto hm = std::make_shared<VerticalMenu>(6, 2);
    hm->addWidget(m1);
    hm->addWidget(m2);
    hm->addWidget(m3);

    MainLoop ml(hm);
    ml.run();
}
