
#ifndef _NV_WINDOW_H
#define _NV_WINDOW_H

#include"nvwm.h"
#include"nvFocusManager.h"
#include"nvSubwidgetManager.h"

typedef struct {
    nvFocusManager *focusManager;
    nvSubwidgetManager *subwidgetManager;
} nvWindow;

nvWidget *nvWindow__new(int x, int y, int width, int height);

void nvWindow_delete(nvWidget * this);

void nvWindow_addWidget(nvWidget * this, nvWidget* widget);

bool nvWindow_receiveKey(nvWidget * this, int ch);

void nvWindow_refresh(nvWidget * this);

bool nvWindow_doesOverlapClientRect(nvWidget* this, nvWidget* that);
#endif
