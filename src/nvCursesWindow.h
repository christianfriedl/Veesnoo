
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
void nvCursesWindow_attrOn(nvCursesWindow * this, int attr);
void nvCursesWindow_attrOff(nvCursesWindow * this, int attr);
void nvCursesWindow_addCh(nvCursesWindow * this, int ch);

#endif
