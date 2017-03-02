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


namespace nv {

    const int Key_Esc = 27;

    class Exception {
    public:
        Exception(std::string msg) {}
    };

}

#endif
