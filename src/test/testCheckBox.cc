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


#include "CursesWindow.h"
#include "CheckBox.h"

using namespace veesnoo;

int main() {
    CheckBox c1(2, 2);
    c1.refresh();
    move(10, 10);
    getch();

    c1.focus();
    c1.refresh();
    move(10, 10);
    getch();

    c1.receiveKey(' ');
    c1.refresh();
    move(10, 10);
    getch();

    CheckBox c2(2, 3);
    c2.setFrame("()");
    c2.refresh();
    move(10, 10);
    getch();

    c2.focus();
    c2.refresh();
    move(10, 10);
    getch();

    c2.receiveKey(' ');
    c2.refresh();
    move(10, 10);
    getch();
}
