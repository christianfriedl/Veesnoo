
#ifndef _NV_ACTIION_LABEL_H
#define _NV_ACTIION_LABEL_H

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
} nvButton;

nvWidget *nvButton__new(int x, int y, cgString * text);

void nvButton_delete(nvWidget * this);

void nvButton_refresh(nvWidget * this);

bool nvButton_receiveKey(nvWidget * this, int ch);

void nvButton_setText(nvWidget * this, cgString * text);

cgString *nvButton_getText(nvWidget * this);

bool nvButton_getIsFocused(nvWidget* this);

bool nvButton_focus(nvWidget * this);

bool nvButton_deFocus(nvWidget * this);

void nvButton_setOnPushMethod(nvWidget* this, void(*method)(nvWidget*));

void nvButton_push(nvWidget * this);

void nvButton_setInputMode(nvWidget * this, nvInputMode mode);
#endif
