#ifndef _NV_SUBWIDGET_MANAGER_H
#define _NV_SUBWIDGET_MANAGER_H

#include<cgenerics/cgArray.h>
#include<cgenerics/cgArrayIterator.h>
#include"nvWidget.h"

DECLARE_ARRAY(nvWidget)
DECLARE_ARRAY_ITERATOR(nvWidget)

typedef struct {
    cgArray(nvWidget)* subWidgets;
} nvSubwidgetManager;

nvSubwidgetManager* nvSubwidgetManager__new();
void nvSubwidgetManager_delete(nvSubwidgetManager* this);

void nvSubwidgetManager_addWidget(nvSubwidgetManager* this, nvWidget* widget);
void nvSubwidgetManager_refresh(nvSubwidgetManager* this);

#endif
