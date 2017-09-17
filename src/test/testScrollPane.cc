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


#include <ncursesw/ncurses.h>
#include "ScrollPane.h"

using namespace nv;

int main() {
    auto s1(std::make_shared<ScrollPane>(Rect(1, 1, 10, 10)));
    int ch = getch();
    while ( true ) {
        for (int x = 0; x < 10; ++x)
            for (int y = 0; y < 10; ++y)
                s1->addChUnscrolled('*', x, y);

        if ( ch == 'h' )
            s1->scrollBy(-1, 0);
        else if ( ch == 'l' )
            s1->scrollBy(1, 0);
        else if ( ch == 'k' )
            s1->scrollBy(0, -1);
        else if ( ch == 'j' )
            s1->scrollBy(0, 1);
        else if ( ch == 27 || ch == 'q' )
            return 0;

        s1->addString("0123456789", 0, 0);
        s1->addString("abcdefghij", 0, 1);
        s1->addString("klmnopqrs", 0, 2);
        s1->refresh();
        ch = getch();
    }
}

