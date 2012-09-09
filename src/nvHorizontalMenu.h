
#ifndef _NV_HORIZONTAL_MENU_H
#define _NV_HORIZONTAL_MENU_H

#include"nvwm.h"
#include"nvFocusManager.h"
#include"nvSubwidgetManager.h"

typedef struct {
    nvFocusManager *focusManager;
    nvSubwidgetManager *subwidgetManager;
    bool isFocused;
} nvHorizontalMenu;

nvWidget *nvHorizontalMenu__new(int x, int y);

void nvHorizontalMenu_delete(nvWidget * this);

void nvHorizontalMenu_addWidget(nvWidget * this, nvWidget * widget);

bool nvHorizontalMenu_receiveKey(nvWidget * this, int ch);

void nvHorizontalMenu_refresh(nvWidget * this);

bool nvHorizontalMenu_doesOverlapClientRect(nvWidget * this, nvWidget * that);

void nvHorizontalMenu_setInputMode(nvWidget * this, nvInputMode mode);

bool nvHorizontalMenu_focus(nvWidget* this);

bool nvHorizontalMenu_deFocus(nvWidget* this);
#endif
