
#ifndef _NV_WIDGET_H
#define _NV_WIDGET_H

#include<ncurses.h>
#include<stdlib.h>
#include<cgenerics/cgAppState.h>

struct nvWidget_struct;

typedef struct nvWidget_struct nvWidget;

#include"nvCollections.h"

#include"nvCursesWindow.h"

typedef enum { nvWidgetType_label = 1, nvWidgetType_textbox, nvWidgetType_checkbox, nvWidgetType_window, nvWidgetType_actionLabel,
    nvWidgetType_horizontalMenu
} nvWidgetType;

struct nvWidget_struct {
    void (*refreshMethod) (nvWidget * this);
    void (*moveMethod) (nvWidget * this, int x, int y);
     bool(*receiveKeyMethod) (nvWidget * this, int ch);
    void (*setInputModeMethod) (nvWidget * this, nvInputMode mode);
     bool(*doesOverlapClientRectMethod) (nvWidget * this, nvWidget * that);
     bool(*focusMethod) (nvWidget * this);
     bool(*defocusMethod) (nvWidget * this);
    void *data;
    nvCursesWindow *cw;
    nvWidgetType type;
    int x, y, width, height;
    bool isVisible;
    nvWidget *parent;
};

/* internal ("protected") methods */
nvWidget *nvWidget__new_(nvWidgetType type, int x, int y, int width, int height, void *data);

nvWidget *nvWidget_clone(const nvWidget * this);

/* needed for use in cgArray, should trigger an exception */
void nvWidget_delete(nvWidget * this);

void nvWidget_delete_(nvWidget * this);

/* public methods */

/* getters'n'setters */

void nvWidget_delete_(nvWidget * this);

int nvWidget_getX(nvWidget * this);

int nvWidget_getY(nvWidget * this);

int nvWidget_getWidth(nvWidget * this);

int nvWidget_getHeight(nvWidget * this);

bool nvWidget_getIsVisible(nvWidget * this);

void nvWidget_setIsVisible(nvWidget * this, bool isVisible);

nvWidget *nvWidget_getParent(nvWidget * this);

void nvWidget_setParent(nvWidget * this, nvWidget * parent);

/* methods */

void nvWidget_refresh(nvWidget * this);

void nvWidget_resize(nvWidget * this, int width, int height);

void nvWidget_move(nvWidget * this, int x, int y);

bool nvWidget_receiveKey(nvWidget * this, int ch);

void nvWidget_setInputMode(nvWidget * this, nvInputMode mode);

bool nvWidget_doesOverlapClientRect(nvWidget * this, nvWidget * that);

bool nvWidget_focus(nvWidget * this);

bool nvWidget_deFocus(nvWidget * this);

/* method setters for subclasses */

void nvWidget_setRefreshMethod(nvWidget * this, void (*moveMethod) (nvWidget *));

void nvWidget_setMoveMethod(nvWidget * this, void (*moveMethod) (nvWidget * this, int x, int y));

void nvWidget_setReceiveKeyMethod(nvWidget * this, bool(*receiveKeyMethod) (nvWidget *, int));

void nvWidget_setDoesOverlapClientRectMethod(nvWidget * this, bool(*doesOverlapClientRectMethod) (nvWidget *, nvWidget *));

void nvWidget_setFocusMethod(nvWidget * this, bool(*method) (nvWidget *));

void nvWidget_setDefocusMethod(nvWidget * this, bool(*method) (nvWidget *));
#endif
