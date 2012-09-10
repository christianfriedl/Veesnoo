#include<cgenerics/cgRectangle.h>
#include"nvWindow.h"

static nvWindow *nvWindow__new_(int x, int y, int width, int height);

static void nvWindow_packWidget_(nvWidget * this, nvWidget * widget);

static nvWindow *nvWindow__new_(int x, int y, int width, int height) {
    nvWindow *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->focusManager = nvFocusManager__new();
        this->subwidgetManager = nvSubwidgetManager__new();
        this->resizeMode = nvWindowResizeMode_fromWindow;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvWindow");
    return this;
}

nvWidget *nvWindow__new(int x, int y, int width, int height) {
    nvWindow *window = nvWindow__new_(x, y, width, height);

    nvWidget *this = nvWidget__new_(nvWidgetType_window, x, y, width, height, (void *)window);

    nvWidget_setRefreshMethod(this, nvWindow_refresh);
    nvWidget_setReceiveKeyMethod(this, nvWindow_receiveKey);
    nvWidget_setDoesOverlapClientRectMethod(this, nvWindow_doesOverlapClientRect);

    return this;
}

void nvWindow_delete(nvWidget * this) {
    nvFocusManager_delete(THIS(nvWindow)->focusManager);
    nvSubwidgetManager_delete(THIS(nvWindow)->subwidgetManager);
    nvWidget_delete_(this);
}

void nvWindow_addWidget(nvWidget * this, nvWidget * widget) {
    /*
     * move relative to absolute coordinates 
     */
    nvWidget_move(widget, nvWidget_getX(widget) + nvWidget_getX(this) + 1, nvWidget_getY(widget) + nvWidget_getY(this) + 1);
    nvWindow_packWidget_(this, widget);
    nvFocusManager_addWidget(THIS(nvWindow)->focusManager, widget);
    nvWidget_setParent(widget, this);
    nvSubwidgetManager_addWidget(THIS(nvWindow)->subwidgetManager, widget);
}

/* adjust either the window's size, or the subwidgets' size, depending on
 * nvWindowResizeMode
 * NOTE: this function assumes that the subwidgets already have absolute coordinates!
 */
void nvWindow_pack(nvWidget * this) {
    cgArrayIterator(nvWidget) * iter =
        cgArrayIterator__new(nvWidget, nvSubwidgetManager_getSubWidgets(THIS(nvWindow)->subwidgetManager));
    nvWidget *widget = NULL;

    while ((widget = cgArrayIterator_fetch(nvWidget, iter)) != NULL)
        nvWindow_packWidget_(this, widget);
}

static void nvWindow_packWidget_(nvWidget * this, nvWidget * widget) {
    if (THIS(nvWindow)->resizeMode == nvWindowResizeMode_fromWindow) {  /* resize widget to fit in window */
        if (nvWindow_doesOverlapClientRect(this, widget) != true)
                return;
        if (nvWidget_getWidth(widget) + nvWidget_getX(widget) - nvWidget_getX(this) > nvWidget_getWidth(this) - 1)
            nvWidget_resize(widget, nvWidget_getWidth(this) - (nvWidget_getX(widget) - nvWidget_getX(this)) - 1,
                            nvWidget_getHeight(widget));
        if (nvWidget_getHeight(widget) + nvWidget_getY(widget) - nvWidget_getY(this) > nvWidget_getHeight(this) - 1)
            nvWidget_resize(widget, nvWidget_getWidth(widget),
                            nvWidget_getHeight(this) - (nvWidget_getY(widget) - nvWidget_getY(this)) - 1);
    } else {                    /* resize window to accomodate child */
        int maxX = nvWidget_getX(widget) + nvWidget_getWidth(widget) - nvWidget_getX(this);

        int maxY = nvWidget_getY(widget) + nvWidget_getHeight(widget) - nvWidget_getY(this);

        int newWidth = this->width;
        int newHeight = this->height;

        if (maxX > nvWidget_getWidth(this) - 1)
            newWidth = maxX + 1;
        if (maxY > nvWidget_getHeight(this) - 1)
            newHeight = maxY + 1;
        nvWidget_resize(this, newWidth, newHeight);
    }
}

bool nvWindow_receiveKey(nvWidget * this, int ch) {
    bool rv = nvFocusManager_receiveKey(THIS(nvWindow)->focusManager, ch);

    /*
     * TODO handle remaining keys? 
     */
    return rv;
}

void nvWindow_refresh(nvWidget * this) {
    nvCursesWindow_addBorder(this->cw);
    nvSubwidgetManager_refresh(THIS(nvWindow)->subwidgetManager);
    nvCursesWindow_refresh(this->cw);
}

bool nvWindow_doesOverlapClientRect(nvWidget * this, nvWidget * that) {
    cgRectangle *rThis = cgRectangle__new(this->x + 1, this->y + 1, this->width - 2, this->height - 2);

    cgRectangle *rThat = cgRectangle__new(that->x, that->y, that->width, that->height);

    bool rv = cgRectangle_doesOverlap(rThis, rThat);

    cgRectangle_delete(rThis);
    cgRectangle_delete(rThat);
    return rv;
}

void nvWindow_setResizeMode(nvWidget * this, nvWindowResizeMode mode) {
    THIS(nvWindow)->resizeMode = mode;
}
