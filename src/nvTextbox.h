#ifndef _NV_LABEL_H
#define _NV_LABEL_H

#include<stdlib.h>
#include<ncurses.h>
#include<cgenerics/cgString.h>
#include"nvwm.h"
#include"nvCursesWindow.h"
#include"nvWidget.h"

typedef struct {
    cgString* text;
    nvInputMode inputMode;
    unsigned int cursorPos;
} nvTextbox;

nvWidget *nvTextbox__new(int x, int y, cgString * text);
void nvTextbox_delete(nvWidget* this);
void nvTextbox_setInputMode(nvWidget* this, nvInputMode mode);
void nvTextbox_refresh(nvWidget* this);
void nvTextbox_receiveKey(nvWidget * this, char ch);
void nvTextbox_setText(nvWidget* this, cgString* text);
void nvTextbox_setInputMode(nvWidget* this, nvInputMode mode);


#endif
