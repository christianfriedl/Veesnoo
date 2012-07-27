
#ifndef _NV_LABEL_H
#define _NV_LABEL_H

#include<stdlib.h>
#include<ncurses.h>
#include<cgenerics/cgString.h>
#include"nvwm.h"
#include"nvCursesWindow.h"
#include"nvWidget.h"

typedef struct {
    cgString *text;
    cgString *oldText;
    nvInputMode inputMode;
    unsigned int cursorPos;
    unsigned int displaySize;
} nvTextbox;

nvWidget *nvTextbox__new(int x, int y, cgString * text, unsigned int displaySize);

void nvTextbox_delete(nvWidget * this);

void nvTextbox_setInputMode(nvWidget * this, nvInputMode mode);

void nvTextbox_refresh(nvWidget * this);

bool nvTextbox_receiveKey(nvWidget * this, int ch);

void nvTextbox_setText(nvWidget * this, cgString * text);

cgString *nvTextbox_getText(nvWidget * this);

void nvTextbox_setInputMode(nvWidget * this, nvInputMode mode);
#endif
