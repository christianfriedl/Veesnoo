
#ifndef _NV_WIDGET_H
#define _NV_WIDGET_H

#include<ncurses.h>
#include<stdlib.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesWindow.h"

typedef enum { nvWidgetType_label = 1 } nvWidgetType;

struct nvWidget_struct;
typedef struct nvWidget_struct nvWidget;
struct nvWidget_struct {
    void (*refresh) (nvWidget *this);
    void (*move) (nvWidget *this);
    void (*receiveKey) (nvWidget *this, char ch);
    void *data;
    nvCursesWindow *cw;
    nvWidgetType type;
    int x, y, width, height;
} ;

/* internal ("protected") methods */

nvWidget *nvWidget__new_(nvWidgetType type, int x, int y, int width, int height,
                         void *data);
void nvWidget_delete_(nvWidget * this);

/* public methods */

void nvWidget_refresh(nvWidget * this);

void nvWidget_resize(nvWidget* this, int width, int height);

/* method setters for subclasses */

void nvWidget_setRefresh(nvWidget * this, void (*move) (nvWidget *));

void nvWidget_setMove(nvWidget * this, void (*move) (nvWidget *));

void nvWidget_setReceiveKey(nvWidget * this, void (*receiveKey) (nvWidget *, char));
#endif
