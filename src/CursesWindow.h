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


#ifndef NV_CURSES_WINDOW_H
#define NV_CURSES_WINDOW_H

#include "NVBase.h"
#include "CursesManager.h"

namespace veesnoo {

    class ColorAttribute;

    class CursesWindow {

        public:
            CursesWindow(const Rect& rect);
            ~CursesWindow();
            void addString(const std::string& text);
            void addString(const std::string& text, int x, int y);
            void addCh(int ch, int x, int y);
            void refresh();
            void noutrefresh();
            void addBorder();
            void addCh(int ch);
            int width();
            int height();
            void attrOn(int attr);
            void attrOff(int attr);
            void pairOn(int apair);
            void pairOff(int apair);
            void resetColors();
            void resize(int width, int height);
            void move(int x, int y);
            void fillBackground(int ch);
            int getWidth();
            int getHeight();
            void setCursorPosition(const int x, const int y);
            void startColorAttribute(const ColorAttribute& attribute);
            void startColorAttribute(std::shared_ptr<ColorAttribute> attribute);
            void endColorAttribute(const ColorAttribute& attribute);
            void endColorAttribute(std::shared_ptr<ColorAttribute> attribute);

            // just for testing
            WINDOW *getWin() { return window_; }

        private:
            WINDOW *window_;
            static int getCursAttr(const ColorAttribute& attribute);

    };

}

#endif
