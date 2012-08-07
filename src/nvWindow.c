#include"nvWindow.h"

static nvWindow *nvWindow__new_(int x, int y, int width, int height);

static nvWindow *nvWindow__new_(int x, int y, int width, int height) {
    nvWindow *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->focusManager = nvFocusManager__new();
        this->subwidgetManager = nvSubwidgetManager__new();
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvWindow");
}

nvWidget *nvWindow__new(int x, int y, int width, int height) {
    nvWindow *window = nvWindow__new_(x, y, width, height);

    nvWidget *this = nvWidget__new_(nvWidgetType_window, x, y, width, height, (void *)window);
    nvWidget_setRefreshMethod(this, nvWindow_refresh);
    nvWidget_setReceiveKeyMethod(this, nvWindow_receiveKey);
}

void nvWindow_delete(nvWidget * this) {
    nvFocusManager_delete(THIS(nvWindow)->focusManager);
    nvSubwidgetManager_delete(THIS(nvWindow)->subwidgetManager);
    nvWidget_delete_(this);
}

void nvWindow_addWidget(nvWidget * this) {
}

bool nvWindow_receiveKey(nvWidget * this, int ch) {
}

void nvWindow_refresh(nvWidget * this) {
}
