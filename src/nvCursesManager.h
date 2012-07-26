#ifndef _NV_CURSES_MANAGER_H
#define _NV_CURSES_MANAGER_H

#include<stdlib.h>
#include<ncurses.h>
#include<cgenerics/cgAppState.h>
#include<cgenerics/cgString.h>
#include<cgenerics/cgenerics.h>

/*
 * TODO halfdelay
 */

typedef struct {
	bool            bufferedMode;
	bool            echo;
	int             maxX, maxY;
}               nvCursesManager;

nvCursesManager * nvCursesManager__getInstance();
void            nvCursesManager_delete(nvCursesManager * this);
void            nvCursesManager_initCurses(nvCursesManager * this);
void            nvCursesManager_uninitCurses(nvCursesManager * this);
WINDOW* nvCursesManager_createWindow(nvCursesManager* this, int x, int y, int width, int height);
void nvCursesManager_destroyWindow(nvCursesManager* this, WINDOW* window);
void nvCursesManager_addBorder(nvCursesManager* this, WINDOW* win);
void nvCursesManager_refresh(nvCursesManager* this);
void nvCursesManager_addString(nvCursesManager* this, WINDOW* win, cgString* text);
void nvCursesManager_clearScreen(nvCursesManager* this);

#endif
