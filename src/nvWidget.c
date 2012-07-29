#include"nvWidget.h"

/*
 * "abstract base class", new_ should only be called from derived class
 */
nvWidget *nvWidget__new_(nvWidgetType type, int x, int y, int width, int height, void *data) {
    nvWidget *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->cw = nvCursesWindow__new(x, y, width, height);
        this->data = data;
        this->type = type;
        this->refresh = NULL;
        this->move = NULL;
        this->receiveKey = NULL;
        this->funcSetInputMode = NULL;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvWidget");
    return this;
}

nvWidget *nvWidget_clone(const nvWidget * this) {
    cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_GeneralFatalException,
                     "widget cannot be cloned by design.");
}

void nvWidget_delete(nvWidget * this) {
    cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_GeneralFatalException,
                     "widget cannot be deleted publically by design.");
}
void nvWidget_delete_(nvWidget * this) {
    free(this);
}

void nvWidget_resize(nvWidget * this, int width, int height) {
    nvCursesWindow_moveCursorTo(this->cw, 0, 0);
    nvCursesWindow_resize(this->cw, width, height);
}

void nvWidget_setRefresh(nvWidget * this, void (*refresh) (nvWidget *)) {
    this->refresh = refresh;
}

void nvWidget_setMove(nvWidget * this, void (*move) (nvWidget *)) {
    this->move = move;
}

void nvWidget_setReceiveKey(nvWidget * this, bool(*receiveKey) (nvWidget *, int)) {
    this->receiveKey = receiveKey;
}

bool nvWidget_receiveKey(nvWidget * this, int ch) {
    return (this->receiveKey)(this, ch);
}

void nvWidget_refresh(nvWidget * this) {
    (this->refresh) (this);
}

void nvWidget_setInputMode(nvWidget* this, nvInputMode mode) {
    if (this->funcSetInputMode != NULL)
        (this->funcSetInputMode) (this, mode);
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, nvExceptionID_fatalException, "cannot set input mode because funcSetInputMode is not set");
}
