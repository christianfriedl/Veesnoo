#ifndef _NV_LABEL_H
#define _NV_LABEL_H

#include<stdlib.h>
#include<ncurses.h>
#include<cgenerics/cgString.h>
#include"nvCursesWindow.h"
#include"nvWidget.h"

typedef struct {
    nvCursesWindow* cw;
    cgString* text;
} nvLabel;

nvWidget *nvLabel__new(int x, int y, cgString * text);
void nvLabel_delete(nvWidget* this);
void nvLabel_refresh(nvWidget* this);


#endif
