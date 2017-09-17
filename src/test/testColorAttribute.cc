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


#include <memory>
#include "nvwm.h"

using namespace nv;

int main() {
    Widget w(Rect(0, 0, 20, 20));
    ColorAttribute redBlack(COLOR_RED, COLOR_BLACK);
    ColorAttribute yellowBlue(COLOR_YELLOW, COLOR_BLUE);
    ColorAttribute greenCyan(COLOR_GREEN, COLOR_CYAN);

    ColorAttribute redBlackBold(COLOR_RED, COLOR_BLACK, false, true);
    ColorAttribute yellowBlueBold(COLOR_YELLOW, COLOR_BLUE, false, true);
    ColorAttribute greenCyanBold(COLOR_GREEN, COLOR_CYAN, false, true);
    ColorAttribute greenCyanBoldBlink(COLOR_GREEN, COLOR_CYAN, false, true, false, true);
    ColorAttribute greenCyanBlinkUnderline(COLOR_GREEN, COLOR_CYAN, false, false, true, true);

    int y = 0;

    w.startColorAttribute(redBlack);
    w.addString("red on black", 0, y++);

    w.startColorAttribute(yellowBlue);
    w.addString("yellow on blue", 0, y++);

    w.startColorAttribute(greenCyan);
    w.addString("green on cyan", 0, y++);

    w.startColorAttribute(redBlackBold);
    w.addString("red on black / bold", 0, y++);

    w.startColorAttribute(yellowBlueBold);
    w.addString("yellow on blue / bold", 0, y++);

    w.startColorAttribute(greenCyanBold);
    w.addString("green on cyan / bold", 0, y++);

    w.startColorAttribute(greenCyanBoldBlink);
    w.addString("green on cyan / bold AND blink", 0, y++);
    
    w.startColorAttribute(greenCyanBlinkUnderline);
    w.addString("green on cyan / blink AND underline", 0, y++);

    w.refresh();
    getch();
}
