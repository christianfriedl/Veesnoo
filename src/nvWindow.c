#include"nvWindow.h"

static nvWindow *nvWindow__new_(int x, int y, int width, int height);

static nvWindow *nvWindow__new_(int x, int y, int width, int height) {
    nvWindow *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->focusManager = nvFocusManager__new();
        this->subwidgetManager = nvSubwidgetManager__new();
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvWindow");
    return this;
}

nvWidget *nvWindow__new(int x, int y, int width, int height) {
    nvWindow *window = nvWindow__new_(x, y, width, height);

    nvWidget *this = nvWidget__new_(nvWidgetType_window, x, y, width, height, (void *)window);
    nvWidget_setRefreshMethod(this, nvWindow_refresh);
    nvWidget_setReceiveKeyMethod(this, nvWindow_receiveKey);

    return this;
}

void nvWindow_delete(nvWidget * this) {
    nvFocusManager_delete(THIS(nvWindow)->focusManager);
    nvSubwidgetManager_delete(THIS(nvWindow)->subwidgetManager);
    nvWidget_delete_(this);
}

void nvWindow_addWidget(nvWidget * this, nvWidget* widget) {
    nvWidget_move(widget, nvWidget_getX(widget) + nvWidget_getX(this) + 1, nvWidget_getY(widget) + nvWidget_getY(this) + 1);
    if (nvWidget_getWidth(widget) > nvWidget_getWidth(this) - 2)
        nvWidget_resize(widget, nvWidget_getWidth(this) - 2, nvWidget_getHeight(widget));
    nvFocusManager_addWidget(THIS(nvWindow)->focusManager, widget);
    nvSubwidgetManager_addWidget(THIS(nvWindow)->subwidgetManager, widget);
}

bool nvWindow_receiveKey(nvWidget * this, int ch) {
    bool rv = nvFocusManager_receiveKey(THIS(nvWindow)->focusManager, ch);
    /* TODO handle remaining keys? */
    return rv;
}

void nvWindow_refresh(nvWidget * this) {
    nvCursesWindow_addBorder(this->cw);
    nvSubwidgetManager_refresh(THIS(nvWindow)->subwidgetManager);
    nvCursesWindow_refresh(this->cw);
}
