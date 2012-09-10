
#ifndef _NV_LABEL_H
#define _NV_LABEL_H

#include<stdlib.h>
#include<ctype.h>
#include<ncurses.h>
#include<cgenerics/cgString.h>
#include"nvwm.h"
#include"nvCursesWindow.h"
#include"nvWidget.h"

typedef struct {
    bool value;
    nvInputMode inputMode;
    bool isFocused;
} nvCheckbox;

nvWidget *nvCheckbox__new(int x, int y, bool value);

void nvCheckbox_delete(nvWidget * this);

void nvCheckbox_setInputMode(nvWidget * this, nvInputMode mode);

void nvCheckbox_refresh(nvWidget * this);

bool nvCheckbox_receiveKey(nvWidget * this, int ch);

void nvCheckbox_setValue(nvWidget * this, bool value);

bool nvCheckbox_getValue(nvWidget * this);

bool nvCheckbox_focus(nvWidget * this);

bool nvCheckbox_deFocus(nvWidget * this);
#endif
