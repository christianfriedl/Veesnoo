
#ifndef _NV_CURSES_WINDOW_H
#define _NV_CURSES_WINDOW_H

struct nvCursesWindow_struct;

typedef struct nvCursesWindow_struct nvCursesWindow;

#include"nvCursesManager.h"

struct nvCursesWindow_struct {
    WINDOW *window;
};

nvCursesWindow *nvCursesWindow__new(int x, int y, int width, int height);

void nvCursesWindow_delete(nvCursesWindow * this);

void nvCursesWindow_addBorder(nvCursesWindow * this);

void nvCursesWindow_addString(nvCursesWindow * this, cgString * text);

void nvCursesWindow_addCh(nvCursesWindow * this, int ch);

void nvCursesWindow_addStringAt(nvCursesWindow * this, int x, int y, cgString * text);

void nvCursesWindow_addChAt(nvCursesWindow * this, int x, int y, int ch);

void nvCursesWindow_attrOn(nvCursesWindow * this, int attr);

void nvCursesWindow_attrOff(nvCursesWindow * this, int attr);

void nvCursesWindow_resize(nvCursesWindow * this, int width, int height);

void nvCursesWindow_moveCursorTo(nvCursesWindow * this, int x, int y);

int nvCursesWindow_getWidth(nvCursesWindow * this);

int nvCursesWindow_getHeight(nvCursesWindow * this);

void nvCursesWindow_refresh(nvCursesWindow * this);

void nvCursesWindow_move(nvCursesWindow * this, int x, int y);

void nvCursesWindow_fillBackground(nvCursesWindow * this, int ch);
#endif
