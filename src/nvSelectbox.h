
#ifndef _NV_SELECTBOX_H
#define _NV_SELECTBOX_H

#include"nvwm.h"
#include"nvActionLabel.h"
#include"nvPopupMenu.h"

typedef struct {
    nvWidget *label;
    nvWidget *menu;
} nvSelectbox;

nvWidget *nvSelectbox__new(int x, int y);

void nvSelectbox_delete(nvWidget * this);

void nvSelectbox_addWidget(nvWidget * this, nvWidget * widget);

bool nvSelectbox_receiveKey(nvWidget * this, int ch);

void nvSelectbox_refresh(nvWidget * this);

bool nvSelectbox_doesOverlapClientRect(nvWidget * this, nvWidget * that);

bool nvSelectbox_focus(nvWidget * this);

bool nvSelectbox_deFocus(nvWidget * this);

void nvSelectbox_show(nvWidget * this);

void nvSelectbox_hide(nvWidget * this);

void nvSelectbox_addItem(nvWidget * this, cgString * label);
#endif
