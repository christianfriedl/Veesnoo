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


#ifndef NV_SCROLLPANE_H
#define NV_SCROLLPANE_H

#include "FocusableContainer.h"
#include "Rect.h"

/*

            ->  scroll(2,0)
   +...+                   +...+
   |ab+---+                |a+---+
   |zy||  |                |z|x| |
   +..|+  |                +.|.+ |
      +---+                  +---+

*/

namespace veesnoo {

    class ScrollPane: public FocusableContainer {
        public:
            ScrollPane(Rect rect); 
            void addString(const std::string& text); 
            void addString(const std::string& text, const int x, const int y); 
            void addStringUnscrolled(const std::string& text);
            void addStringUnscrolled(const std::string& text, const int x, const int y);
            void addCh(int ch);
            void addCh(const int ch, const int x, const int y); 
            void addChUnscrolled(const int ch);
            void addChUnscrolled(const int ch, const int x, const int y);
            void scrollBy(const int deltaX, const int deltaY);
            void scrollTo(const int x, const int y);

        private:
            Point viewPort_;
    };

}
#endif
