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


#ifndef NV_CURSES_MANAGER_H
#define NV_CURSES_MANAGER_H

#include "NVBase.h"
#include "Rect.h"

namespace veesnoo {

    class CursesManager {
        public:
            static CursesManager& get();
            
            WINDOW *createWindow(int x ,int y ,int width ,int height);
            void destroyWindow(WINDOW *window);
            void refresh();
            void doupdate();
            Rect getMaxScreenRect();
            int colorPair(short int fg, short int bg);
            int numPairs();
            int findPair(short int fg, short int bg);
            int getCh();
            const char * getKeyName(int ch) const;
        private:
            void initCurses();
            CursesManager(); 
            ~CursesManager();

            CursesManager(const CursesManager&);
            CursesManager& operator=(const CursesManager&);

            bool bufferedMode_;
            bool cBreak_;
            bool echo_;
            bool keypadAvailable_;
            int width_, height_;
            int numPairs_;
    };

}

#endif
