
#ifndef _NV_SUBWIDGET_MANAGER_H
#define _NV_SUBWIDGET_MANAGER_H

#include"nvwm.h"
#include"nvWidget.h"

typedef struct {
    cgArray(nvWidget) * subWidgets;
} nvSubwidgetManager;

nvSubwidgetManager *nvSubwidgetManager__new();

void nvSubwidgetManager_delete(nvSubwidgetManager * this);

void nvSubwidgetManager_addWidget(nvSubwidgetManager * this, nvWidget * widget);

void nvSubwidgetManager_refresh(nvSubwidgetManager * this);

cgArray(nvWidget) * nvSubwidgetManager_getSubWidgets(nvSubwidgetManager * this);
#endif
