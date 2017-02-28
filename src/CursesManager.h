#ifndef NV_CURSES_MANAGER_H
#define NV_CURSES_MANAGER_H

#ifdef HAVE_USR_INCLUDE_NCURSES_H
    #include <ncurses.h>
#elif HAVE_USR_INCLUDE_NCURSESW_NCURSES_H
    #include <ncursesw/ncurses.h>
#else
    #error "no curses header file set"
#endif

#include "NVBase.h"
#include "Rect.h"

namespace nv {

class CursesManager {
public:
    static CursesManager& getInstance();
    
    WINDOW *createWindow(int x ,int y ,int width ,int height);
    void destroyWindow(WINDOW *window);
    void refresh();
    Rect *getMaxScreenRect();
    int colorPair(int fg, int bg);
private:
    void initCurses();
    CursesManager(); 
    ~CursesManager();

    CursesManager(const CursesManager&);
    CursesManager& operator=(const CursesManager&);

    bool bufferedMode;
    bool echo;
    bool keypadAvailable;
    int width, height;
    int nextPair;
};

}

#endif
