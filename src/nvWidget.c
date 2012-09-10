#include<cgenerics/cgRectangle.h>
#include"nvWidget.h"

static bool nvWidget_doesOverlapClientRect_(nvWidget * this, nvWidget * that);

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
        this->isVisible = true;
        this->refreshMethod = NULL;
        this->moveMethod = NULL;
        this->receiveKeyMethod = NULL;
        this->setInputModeMethod = NULL;
        this->doesOverlapClientRectMethod = nvWidget_doesOverlapClientRect_;
        this->focusMethod = NULL;
        this->defocusMethod = NULL;
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

/* getters'n'setters */
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

bool nvWidget_getIsVisible(nvWidget * this) {
    return this->isVisible;
}

void nvWidget_setIsVisible(nvWidget * this, bool isVisible) {
    this->isVisible = isVisible;
}

nvWidget *nvWidget_getParent(nvWidget * this) {
    return this->parent;
}

void nvWidget_setParent(nvWidget * this, nvWidget * parent) {
    this->parent = parent;
}

/* setters for methods */
void nvWidget_setRefreshMethod(nvWidget * this, void (*refreshMethod) (nvWidget *)) {
    this->refreshMethod = refreshMethod;
}

void nvWidget_setMoveMethod(nvWidget * this, void (*moveMethod) (nvWidget * this, int x, int y)) {
    this->moveMethod = moveMethod;
}

void nvWidget_setReceiveKeyMethod(nvWidget * this, bool(*receiveKeyMethod) (nvWidget *, int)) {
    this->receiveKeyMethod = receiveKeyMethod;
}

void nvWidget_setDoesOverlapClientRectMethod(nvWidget * this, bool(*doesOverlapClientRectMethod) (nvWidget *, nvWidget *)) {
    this->doesOverlapClientRectMethod = doesOverlapClientRectMethod;
}

void nvWidget_setFocusMethod(nvWidget * this, bool(*method) (nvWidget *)) {
    this->focusMethod = method;
}

void nvWidget_setDefocusMethod(nvWidget * this, bool(*method) (nvWidget *)) {
    this->defocusMethod = method;
}

/* methods */

/* @NonVirtual */
void nvWidget_resize(nvWidget * this, int width, int height) {
    nvCursesWindow_moveCursorTo(this->cw, 0, 0);
    nvCursesWindow_resize(this->cw, width, height);
    this->width = width;
    this->height = height;
}

/* @Virtual @Implemented */
void nvWidget_move(nvWidget * this, int x, int y) {
    if (this->moveMethod != NULL)
        (this->moveMethod) (this, x, y);
    else {
        nvCursesWindow_move(this->cw, x, y);
        this->x = x;
        this->y = y;
    }
}

/* @Virtual @Abstract */
bool nvWidget_receiveKey(nvWidget * this, int ch) {
    return (this->receiveKeyMethod) (this, ch);
}

/* @Virtual, @Abstract */
void nvWidget_refresh(nvWidget * this) {
    (this->refreshMethod) (this);
}

/* @Virtual @Implemented */
bool nvWidget_doesOverlapClientRect(nvWidget * this, nvWidget * that) {
    return (this->doesOverlapClientRectMethod) (this, that);
}

/* default implementation
 * TODO the name stinks
 */
static bool nvWidget_doesOverlapClientRect_(nvWidget * this, nvWidget * that) {
    cgRectangle *rThis = cgRectangle__new(this->x, this->y, this->width, this->height);

    cgRectangle *rThat = cgRectangle__new(that->x, that->y, that->width, that->height);

    bool rv = cgRectangle_doesOverlap(rThis, rThat);

    cgRectangle_delete(rThis);
    cgRectangle_delete(rThat);
    return rv;
}

void nvWidget_setInputMode(nvWidget * this, nvInputMode mode) {
    if (this->setInputModeMethod != NULL)
        (this->setInputModeMethod) (this, mode);
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, nvExceptionID_fatalException,
                         "cannot set input mode because setInputModeMethod is not set");
}

/* @Virtual @Abstract
 * NOTE: this sets the global focused widget in the curses manager before calling the derived method
 */
bool nvWidget_focus(nvWidget * this) {
    nvCursesManager_setFocusedWidget(nvCursesManager__getInstance(), this);
    if (this->focusMethod != NULL)
        return (this->focusMethod) (this);
    else {
        cgAppState_THROW(cgAppState__getInstance(), Severity_warning, cgExceptionID_NoSuchMethod, "%s called on raw nvWidget of class %i", __func__, this->type);
        return false;
    }
}

bool nvWidget_deFocus(nvWidget * this) {
    if (this->defocusMethod != NULL)
        return (this->defocusMethod) (this);
    else {
        cgAppState_THROW(cgAppState__getInstance(), Severity_warning, cgExceptionID_NoSuchMethod, "%s called on raw nvWidget of class %i", __func__, this->type);
        return false;
    }
}
