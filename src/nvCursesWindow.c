#include<ncurses.h>
#include<stdlib.h>
#include<cgenerics/cgAppState.h>
#include<cgenerics/cgenerics.h>
#include"nvwm.h"
#include"nvCursesWindow.h"

nvCursesWindow *nvCursesWindow__new(int x, int y, int width, int height) {
    nvCursesWindow *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->window = nvCursesManager_createWindow(nvCursesManager__getInstance(), x, y, width, height);
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal,
                         cgExceptionID_CannotAllocate, "unable to allocate nvCursesWindow");
    return this;
}

void nvCursesWindow_delete(nvCursesWindow * this) {
    nvCursesManager_destroyWindow(nvCursesManager__getInstance(), this->window);
}

void nvCursesWindow_addBorder(nvCursesWindow * this) {
    box(this->window, 0, 0);
    wnoutrefresh(this->window);
    nvCursesManager_refresh(nvCursesManager__getInstance());
}

void nvCursesWindow_addString(nvCursesWindow * this, cgString * text) {
    int x, y;

    getyx(this->window, y, x);
    nvCursesWindow_addStringAt(this, x, y, text);
}

void nvCursesWindow_addCh(nvCursesWindow * this, int ch) {
    int x, y;

    getyx(this->window, y, x);
    nvCursesWindow_addChAt(this, x, y, ch);
}

void nvCursesWindow_addStringAt(nvCursesWindow * this, int x, int y, cgString * text) {
    int width, height;

    getmaxyx(this->window, height, width);
    mvwaddnstr(this->window, y, x, text, min(cgString_getSize(text), width - x));
    wnoutrefresh(this->window);
}

int nvCursesWindow_getWidth(nvCursesWindow * this) {
    int width, height;

    getmaxyx(this->window, height, width);
    return width;
}

int nvCursesWindow_getHeight(nvCursesWindow * this) {
    int width, height;

    getmaxyx(this->window, height, width);
    return height;
}

void nvCursesWindow_addChAt(nvCursesWindow * this, int x, int y, int ch) {
    /*
     * TODO check constraints 
     */
    mvwaddch(this->window, y, x, ch);
    wnoutrefresh(this->window);
}

void nvCursesWindow_attrOn(nvCursesWindow * this, int attr) {
    wattron(this->window, attr);
}

void nvCursesWindow_attrOff(nvCursesWindow * this, int attr) {
    wattroff(this->window, attr);
}

void nvCursesWindow_resize(nvCursesWindow * this, int width, int height) {
    if ((wresize(this->window, height, width)) == ERR)
        cgAppState_THROW(cgAppState__getInstance(), Severity_error, nvExceptionID_nonfatalException, "unable to resize window (width=%i, height=%i)", width, height);
}

void nvCursesWindow_moveCursorTo(nvCursesWindow * this, int x, int y) {
    wmove(this->window, y, x);
    /*
     * if ((wmove(this->window, y, x)) == ERR)
     * cgAppState_THROW(cgAppState__getInstance(), Severity_error, nvExceptionID_nonfatalException, "unable to move cursor");
     */
    wnoutrefresh(this->window);
}

void nvCursesWindow_refresh(nvCursesWindow * this) {
    /*
     * prepare code for later on, for more effectivity:
     * * if (nvWindowManager__hasInstance())
     * *     nvWindowManager_setRefreshNecessary();
     * * else
     * *     doupdate();
     */
    doupdate();
}

void nvCursesWindow_move(nvCursesWindow * this, int x, int y) {
    if ((mvwin(this->window, y, x)) != OK)
        cgAppState_THROW(cgAppState__getInstance(), Severity_error, nvExceptionID_nonfatalException, "unable to move window (x=%i, y=%i)", x, y);
}

void nvCursesWindow_fillBackground(nvCursesWindow * this, int ch) {
    int x, y, maxx, maxy;
    getmaxyx(this->window, maxy, maxx);
    for (y = 0; y < maxy; ++y)
        for (x = 0; x < maxx; ++x)
            nvCursesWindow_addChAt(this, x, y, ch);
}
