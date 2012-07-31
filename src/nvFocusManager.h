
#ifndef _NV_FOCUS_MANAGER_H
#define _NV_FOCUS_MANAGER_H

#include<stdlib.h>
#include<ctype.h>
#include<ncurses.h>
#include<cgenerics/cgArray.h>
#include"nvwm.h"
#include"nvCursesWindow.h"
#include"nvWidget.h"

typedef struct {
    cgArray(nvWidget) * widgets;
    nvWidget *focusedWidget;
} nvFocusManager;

nvFocusManager *nvFocusManager__new();

void nvFocusManager_delete(nvFocusManager * this);

bool nvFocusManager_receiveKey(nvFocusManager * this, int ch);

void nvFocusManager_addWidget(nvFocusManager * this, nvWidget * widget);

nvWidget *nvFocusManager_getFocusedWidget(nvFocusManager * this);
#endif
