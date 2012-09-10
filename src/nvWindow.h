
#ifndef _NV_WINDOW_H
#define _NV_WINDOW_H

#include"nvwm.h"
#include"nvWidget.h"
#include"nvFocusManager.h"
#include"nvSubwidgetManager.h"

typedef enum { nvWindowResizeMode_fromWindow = 0, nvWindowResizeMode_fromChildren } nvWindowResizeMode;

typedef struct {
    nvFocusManager *focusManager;
    nvSubwidgetManager *subwidgetManager;
    nvWindowResizeMode resizeMode;
    bool isFocused;
} nvWindow;

nvWidget *nvWindow__new(int x, int y, int width, int height);

void nvWindow_delete(nvWidget * this);

void nvWindow_addWidget(nvWidget * this, nvWidget * widget);

bool nvWindow_receiveKey(nvWidget * this, int ch);

void nvWindow_refresh(nvWidget * this);

bool nvWindow_doesOverlapClientRect(nvWidget * this, nvWidget * that);

void nvWindow_pack(nvWidget * this);

void nvWindow_setResizeMode(nvWidget * this, nvWindowResizeMode mode);

bool nvWindow_focus(nvWidget * this);

bool nvWindow_deFocus(nvWidget * this);

void nvWindow_show(nvWidget * this);

void nvWindow_hide(nvWidget * this);
#endif
