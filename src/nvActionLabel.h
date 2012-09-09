
#ifndef _NV_TEXTBOX_H
#define _NV_TEXTBOX_H

#include<stdlib.h>
#include<ctype.h>
#include<ncurses.h>
#include<cgenerics/cgString.h>
#include"nvwm.h"
#include"nvCursesWindow.h"
#include"nvWidget.h"

typedef struct {
    cgString *text;
    bool isFocused;
    void(*onPushMethod)(nvWidget*);
} nvActionLabel;

nvWidget *nvActionLabel__new(int x, int y, cgString * text);

void nvActionLabel_delete(nvWidget * this);

void nvActionLabel_refresh(nvWidget * this);

bool nvActionLabel_receiveKey(nvWidget * this, int ch);

void nvActionLabel_setText(nvWidget * this, cgString * text);

cgString *nvActionLabel_getText(nvWidget * this);

bool nvActionLabel_getIsFocused(nvWidget* this);

bool nvActionLabel_focus(nvWidget * this);

bool nvActionLabel_deFocus(nvWidget * this);

void nvActionLabel_setOnPushMethod(nvWidget* this, void(*method)(nvWidget*));

void nvActionLabel_push(nvWidget * this);

#endif
