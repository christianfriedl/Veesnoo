
#ifndef _NV_HORIZONTAL_MENU_H
#define _NV_HORIZONTAL_MENU_H

#include"nvwm.h"
#include"nvFocusManager.h"
#include"nvSubwidgetManager.h"

typedef struct {
    nvFocusManager *focusManager;
    nvSubwidgetManager *subwidgetManager;
    bool isFocused;
} nvVerticalMenu;

nvWidget *nvVerticalMenu__new(int x, int y);

void nvVerticalMenu_delete(nvWidget * this);

void nvVerticalMenu_addWidget(nvWidget * this, nvWidget * widget);

bool nvVerticalMenu_receiveKey(nvWidget * this, int ch);

void nvVerticalMenu_refresh(nvWidget * this);

bool nvVerticalMenu_doesOverlapClientRect(nvWidget * this, nvWidget * that);

void nvVerticalMenu_setInputMode(nvWidget * this, nvInputMode mode);

bool nvVerticalMenu_focus(nvWidget * this);

bool nvVerticalMenu_deFocus(nvWidget * this);

nvSubwidgetManager *nvVerticalMenu_getSubwidgetManager(nvWidget * this);
#endif
