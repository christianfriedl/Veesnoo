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


#ifndef NV_BASE_H
#define NV_BASE_H

#include "config.h"

#ifdef HAVE_NCURSESW_NCURSES_H 
    #include <ncursesw/ncurses.h>
#elif HAVE_NCURSES_H
    #include <ncurses.h>
#else
    #error "no curses header file set"
#endif

#include <string>
#include <iostream>
#include <memory>


namespace veesnoo {

    const int Key_Esc = 27;
    const int Key_Enter = 10;

    class Exception {
    public:
        Exception(std::string msg): msg_(msg) { }
    private:
        std::string msg_;
    };

}

#endif
