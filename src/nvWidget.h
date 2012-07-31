
#ifndef _NV_WIDGET_H
#define _NV_WIDGET_H

#include<ncurses.h>
#include<stdlib.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesWindow.h"

typedef enum { nvWidgetType_label = 1, nvWidgetType_textbox, nvWidgetType_checkbox } nvWidgetType;

struct nvWidget_struct;

typedef struct nvWidget_struct nvWidget;

struct nvWidget_struct {
    void (*refreshMethod) (nvWidget * this);
    void (*moveMethod) (nvWidget * this);
     bool(*receiveKeyMethod) (nvWidget * this, int ch);
    void (*setInputModeMethod) (nvWidget * this, nvInputMode mode);
    void *data;
    nvCursesWindow *cw;
    nvWidgetType type;
    int x, y, width, height;
};

DECLARE_ARRAY(nvWidget)
DECLARE_ARRAY_ITERATOR(nvWidget)


/* internal ("protected") methods */

nvWidget *nvWidget__new_(nvWidgetType type, int x, int y, int width, int height, void *data);

nvWidget *nvWidget_clone(const nvWidget * this);

/* needed for use in cgArray, should trigger an exception */
void nvWidget_delete(nvWidget * this);

void nvWidget_delete_(nvWidget * this);

/* public methods */

void nvWidget_refresh(nvWidget * this);

void nvWidget_resize(nvWidget * this, int width, int height);

bool nvWidget_receiveKey(nvWidget * this, int ch);

/* method setters for subclasses */

void nvWidget_setRefreshMethod(nvWidget * this, void (*moveMethod) (nvWidget *));

void nvWidget_setMoveMethod(nvWidget * this, void (*moveMethod) (nvWidget *));

void nvWidget_setReceiveKeyMethod(nvWidget * this, bool(*receiveKeyMethod) (nvWidget *, int));

void nvWidget_setInputMode(nvWidget* this, nvInputMode mode);
#endif
