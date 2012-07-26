#include<ncurses.h>
#include<stdlib.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesWindow.h"

nvCursesWindow *nvCursesWindow__new(int x, int y, int width, int height) {
    nvCursesWindow *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->window =
            nvCursesManager_createWindow(nvCursesManager__getInstance(),
                                         x, y, width, height);
    }
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal,
                         cgExceptionID_CannotAllocate,
                         "unable to allocate nvCursesWindow");
    return this;
}

void nvCursesWindow_delete(nvCursesWindow * this) {
    nvCursesManager_destroyWindow(nvCursesManager__getInstance(), this->window);
}

void nvCursesWindow_addBorder(nvCursesWindow * this) {
    nvCursesManager_addBorder(nvCursesManager__getInstance(), this->window);
    nvCursesManager_refresh(nvCursesManager__getInstance());
}

void nvCursesWindow_addString(nvCursesWindow * this, cgString * text) {
    waddstr(this->window, text);
    wnoutrefresh(this->window);
}

void nvCursesWindow_addCh(nvCursesWindow * this, int ch) {
    waddch(this->window, ch);
    wnoutrefresh(this->window);
}

void nvCursesWindow_attrOn(nvCursesWindow * this, int attr) {
    wattron(this->window, attr);
}

void nvCursesWindow_attrOff(nvCursesWindow * this, int attr) {
    wattroff(this->window, attr);
}
