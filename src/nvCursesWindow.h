
#ifndef _NV_CURSES_WINDOW_H
#define _NV_CURSES_WINDOW_H

#include"nvCursesManager.h"

typedef struct {
  WINDOW *window;
} nvCursesWindow;

nvCursesWindow *nvCursesWindow__new(int x, int y, int width, int height);
void nvCursesWindow_delete(nvCursesWindow * this);
void nvCursesWindow_addBorder(nvCursesWindow* this);
void nvCursesWindow_addString(nvCursesWindow* this, cgString* text);
void nvCursesWindow_addCh(nvCursesWindow * this, int ch);
void nvCursesWindow_addStringAt(nvCursesWindow* this, int x, int y, cgString* text);
void nvCursesWindow_addChAt(nvCursesWindow * this, int x, int y, int ch);
void nvCursesWindow_attrOn(nvCursesWindow * this, int attr);
void nvCursesWindow_attrOff(nvCursesWindow * this, int attr);
void nvCursesWindow_resize(nvCursesWindow* this, int width, int height);
void nvCursesWindow_moveCursorTo(nvCursesWindow* this, int x, int y);
int nvCursesWindow_getMaxX(nvCursesWindow* this);
int nvCursesWindow_getMaxY(nvCursesWindow* this);

#endif
