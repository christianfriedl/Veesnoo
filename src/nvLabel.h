#ifndef _NV_LABEL_H
#define _NV_LABEL_H

#include<stdlib.h>
#include<ncurses.h>
#include<cgenerics/cgString.h>
#include"nvCursesWindow.h"

typedef struct {
    nvCursesWindow* cw;
    cgString* text;
} nvLabel;

nvLabel* nvLabel__new(int x, int y, cgString* text);
void nvLabel_delete(nvLabel* this);
void nvLabel_refresh(nvLabel* this);


#endif
