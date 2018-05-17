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


#include "CursesManager.h"
#include "Logger.h"

namespace veesnoo {

CursesManager& CursesManager::get() {
    static CursesManager instance = CursesManager();
    return instance;
}

CursesManager::CursesManager() : bufferedMode_(false), cBreak_(false), echo_(false), keypadAvailable_(true), width_(0), height_(0), numPairs_(0) { 
    LOGMETHODONLY();
	initCurses();
}

void CursesManager::initCurses() {
    LOGMETHODONLY();
    setlocale(LC_ALL, "");
    initscr();
    getmaxyx(stdscr, height_, width_);
    if (!bufferedMode_) {
        if (cBreak_)
            cbreak();
        else
            raw();
    }
    if (!echo_) {
        noecho();
    }
    if (keypadAvailable_) {
        keypad(stdscr, TRUE);
        set_escdelay(30);       /* set ESC delay to a very low level so we can use the ESC key AND the function keys ('tis good enough for VIM, 'tis good enough for me) */
    }
    if (has_colors())
        start_color();
    refresh();
}

CursesManager::~CursesManager() {
    LOGMETHODONLY();
    endwin();
}

WINDOW *CursesManager::createWindow(int x ,int y ,int width ,int height) {
    return newwin(height, width, y, x);
}

void CursesManager::destroyWindow(WINDOW *window) {
    delwin(window);
}

void CursesManager::refresh() {
    LOGMETHODONLY();
    ::refresh();
}

void CursesManager::doupdate() {
    LOGMETHODONLY();
    ::doupdate();
}

Rect CursesManager::getMaxScreenRect() {
    int x, y;
    getmaxyx(stdscr, y, x);
    return Rect(0, 0, x, y);
}

int CursesManager::colorPair(short int fg, short int bg) {
    int pair = 0;
    if (!has_colors())
        throw new Exception("this terminal has no colors.");
    pair = ++numPairs_;
    if (init_pair(pair, fg, bg) != OK) {
        LOGMETHOD("could not init color fg=%i, bg=%i", fg, bg);
        throw new Exception("could not init color");
    }
    return pair;
}

int CursesManager::numPairs() {
    return numPairs_;
}

int CursesManager::findPair(short int fg, short int bg) {
    for ( int num = 0; num < numPairs_; ++num ) {
        short int xfg = 0, xbg = 0;
        ::pair_content(num, &xfg, &xbg);
        if ( xfg == fg && xbg == bg )
            return num;
    }
    return 0;
}

int CursesManager::getCh() {
    return getch();
}

const char * CursesManager::getKeyName(int ch) const {
    const char * const name = keyname(ch); // TODO do we need to delete()???
    return name;
}

}
