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
        this->refreshMethod = NULL;
        this->moveMethod = NULL;
        this->receiveKeyMethod = NULL;
        this->setInputModeMethod = NULL;
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

int nvWidget_getX(nvWidget * this) {
    return this->x;
}

int nvWidget_getY(nvWidget * this) {
    return this->y;
}

int nvWidget_getWidth(nvWidget * this) {
    return this->width;
}

int nvWidget_getHeight(nvWidget * this) {
    return this->height;
}

void nvWidget_resize(nvWidget * this, int width, int height) {
    nvCursesWindow_moveCursorTo(this->cw, 0, 0);
    nvCursesWindow_resize(this->cw, width, height);
    this->width = width;
    this->height = height;
}

void nvWidget_move(nvWidget * this, int x, int y) {
    if (this->moveMethod != NULL)
        (this->moveMethod) (this, x, y);
    else
        nvCursesWindow_move(this->cw, x, y);
}

void nvWidget_setRefreshMethod(nvWidget * this, void (*refreshMethod) (nvWidget *)) {
    this->refreshMethod = refreshMethod;
}

void nvWidget_setMoveMethod(nvWidget * this, void (*moveMethod) (nvWidget *)) {
    this->moveMethod = moveMethod;
}

void nvWidget_setReceiveKeyMethod(nvWidget * this, bool(*receiveKeyMethod) (nvWidget *, int)) {
    this->receiveKeyMethod = receiveKeyMethod;
}

bool nvWidget_receiveKey(nvWidget * this, int ch) {
    return (this->receiveKeyMethod) (this, ch);
}

void nvWidget_refresh(nvWidget * this) {
    (this->refreshMethod) (this);
}

void nvWidget_setInputMode(nvWidget * this, nvInputMode mode) {
    if (this->setInputModeMethod != NULL)
        (this->setInputModeMethod) (this, mode);
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, nvExceptionID_fatalException,
                         "cannot set input mode because setInputModeMethod is not set");
}
