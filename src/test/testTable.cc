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


#include "nvwm.h"

using namespace nv;

int main() {
    auto t1(std::make_shared<Table>(Rect(0, 0, 10, 10), 3));
    for (int i = 1; i <= 5; ++i) {
        auto tc1(std::make_shared<Label>("cell", 0, 0));
        t1->addWidget(tc1);
    }
    t1->refresh();
    getch();

}
