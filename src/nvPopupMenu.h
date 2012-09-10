
#ifndef _NV_POPUP_MENU_H
#define _NV_POPUP_MENU_H

#include"nvwm.h"
#include"nvWindow.h"
#include"nvVerticalMenu.h"

typedef struct {
    nvWidget *window;
    nvWidget *menu;
} nvPopupMenu;

nvWidget *nvPopupMenu__new(int x, int y);

void nvPopupMenu_delete(nvWidget * this);

void nvPopupMenu_addWidget(nvWidget * this, nvWidget * widget);

bool nvPopupMenu_receiveKey(nvWidget * this, int ch);

void nvPopupMenu_refresh(nvWidget * this);

bool nvPopupMenu_doesOverlapClientRect(nvWidget * this, nvWidget * that);

bool nvPopupMenu_focus(nvWidget * this);

bool nvPopupMenu_deFocus(nvWidget * this);

void nvPopupMenu_show(nvWidget * this);

void nvPopupMenu_hide(nvWidget * this);
#endif
