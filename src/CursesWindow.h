#ifndef NV_CURSES_WINDOW_H
#define NV_CURSES_WINDOW_H

#include <memory>
#ifdef HAVE_USR_INCLUDE_NCURSES_H
    #include <ncurses.h>
#elif HAVE_USR_INCLUDE_NCURSESW_NCURSES_H
    #include <ncursesw/ncurses.h>
#else
    #error "no curses header file set"
#endif
#include "CursesManager.h"

namespace nv {

class CursesWindow {

public:
    CursesWindow(const Rect& rect);
    ~CursesWindow();
    void addString(const std::string& text);
    void addString(const std::string& text, int x, int y);
    void addCh(int ch, int x, int y);
    void refresh();
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
    void moveCursor(int x, int y);
    void move(int x, int y);
    void fillBackground(int ch);
    int getWidth();
    int getHeight();
    void setCursorPosition(const int x, const int y);

private:
    WINDOW *window;

};

}

#endif
