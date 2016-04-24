#include "CursesManager.h"
#include "Logger.h"

namespace nv {

CursesManager& CursesManager::getInstance() {
    static CursesManager instance = CursesManager();
    Logger::get().log("CursesManager::getInstance called, returns %lld", (void*)&instance);
    return instance;
}

CursesManager::CursesManager() : bufferedMode(false), echo(false), keypadAvailable(true), width(0), height(0), nextPair(1) { 
    Logger::get().log("CursesManager cons called, this is %lld", (void*)this);
	initCurses();
}

void CursesManager::initCurses() {
    initscr();
    getmaxyx(stdscr, height, width);
    if (!bufferedMode) {
        raw();
        cbreak();
    }
    if (!echo) {
        noecho();
    }
    if (keypadAvailable) {
        keypad(stdscr, TRUE);
        set_escdelay(25);       /* set ESC delay to a very low level so we can use the ESC key AND the function keys ('tis good enough for VIM, 'tis good enough for me) */
    }
    if (has_colors())
        start_color();
}

CursesManager::~CursesManager() {
    Logger::get().log("CursesManager destr called, this is %lld", (void*)this);
    endwin();
}

WINDOW *CursesManager::createWindow(int x ,int y ,int width ,int height) {
    return newwin(height, width, y, x);
}

void CursesManager::destroyWindow(WINDOW *window) {
    delwin(window);
}

void CursesManager::refresh() {
    ::refresh();
}

Rect *CursesManager::getMaxScreenRect() {
    int x, y;
    getmaxyx(stdscr, y, x);
    return new Rect(0, 0, x, y);
}

int CursesManager::colorPair(int fg, int bg) {
    int pair = 0;
    if (!has_colors())
        throw new Exception("this terminal has no colors.");
    pair = nextPair++;
    if (init_pair(pair, fg, bg) != OK)
        throw new Exception("could not init color");
    return pair;
}

}
