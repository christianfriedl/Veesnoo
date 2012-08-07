
#ifndef _NV_CURSES_MANAGER_H
#define _NV_CURSES_MANAGER_H

#include<stdlib.h>
#include<ncurses.h>
#include<cgenerics/cgAppState.h>
#include<cgenerics/cgString.h>
#include<cgenerics/cgenerics.h>
#include"nvwm.h"
#include"nvWidget.h"

/*
 * TODO halfdelay
 */

typedef struct {
    bool bufferedMode;
    bool echo;
    bool keypadAvailable;
    int width, height;
    nvWidget *focusedWidget;

} nvCursesManager;

nvCursesManager *nvCursesManager__getInstance();

void nvCursesManager_delete(nvCursesManager * this);

void nvCursesManager_initCurses(nvCursesManager * this);

void nvCursesManager_uninitCurses(nvCursesManager * this);

WINDOW *nvCursesManager_createWindow(nvCursesManager * this, int x, int y, int width, int height);

void nvCursesManager_destroyWindow(nvCursesManager * this, WINDOW * window);

void nvCursesManager_refresh(nvCursesManager * this);

void nvCursesManager_clearScreen(nvCursesManager * this);

int nvCursesManager_getScreenWidth(nvCursesManager * this);

int nvCursesManager_getScreenHeight(nvCursesManager * this);

void nvCursesManager_setFocusedWidget(nvCursesManager * this, nvWidget * widget);

nvWidget *nvCursesManager_getFocusedWidget(nvCursesManager * this);
#endif
