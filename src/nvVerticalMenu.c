#include<cgenerics/cgRectangle.h>
#include"nvVerticalMenu.h"

static nvVerticalMenu *nvVerticalMenu__new_(int x, int y);

static nvVerticalMenu *nvVerticalMenu__new_(int x, int y) {
    nvVerticalMenu *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->focusManager = nvFocusManager__new();
        this->subwidgetManager = nvSubwidgetManager__new();
        this->isFocused = false;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate,
                         "cannot allocate nvVerticalMenu");
    return this;
}

nvWidget *nvVerticalMenu__new(int x, int y) {
    nvVerticalMenu *menu = nvVerticalMenu__new_(x, y);

    nvWidget *this = nvWidget__new_(nvWidgetType_verticalMenu, x, y, 0, 1, (void *)menu);

    nvWidget_setRefreshMethod(this, nvVerticalMenu_refresh);
    nvWidget_setReceiveKeyMethod(this, nvVerticalMenu_receiveKey);
    nvWidget_setFocusMethod(this, nvVerticalMenu_focus);
    nvWidget_setDefocusMethod(this, nvVerticalMenu_deFocus);
    this->setInputModeMethod = nvVerticalMenu_setInputMode;

    return this;
}

void nvVerticalMenu_delete(nvWidget * this) {
    nvFocusManager_delete(THIS(nvVerticalMenu)->focusManager);
    nvSubwidgetManager_delete(THIS(nvVerticalMenu)->subwidgetManager);
    nvWidget_delete_(this);
}

void nvVerticalMenu_addWidget(nvWidget * this, nvWidget * widget) {
    cgArray(nvWidget) * sw = nvSubwidgetManager_getSubWidgets(THIS(nvVerticalMenu)->subwidgetManager);
    int y = cgArray_getSize(nvWidget, sw);

    nvWidget_move(widget, nvWidget_getX(this), y + nvWidget_getY(this));
    nvFocusManager_addWidget(THIS(nvVerticalMenu)->focusManager, widget);
    nvSubwidgetManager_addWidget(THIS(nvVerticalMenu)->subwidgetManager, widget);
    /*
     * resize menu to accomodate widget 
     */
    cgArrayIterator(nvWidget) * iter = cgArrayIterator__new(nvWidget, sw);
    nvWidget *iwidget = NULL;

    int x = 0;

    while ((iwidget = cgArrayIterator_fetch(nvWidget, iter)) != NULL)
        x = max(x, nvWidget_getWidth(iwidget));
    nvWidget_resize(this, x, y + 1);
    nvWidget_setParent(widget, this);
}

bool nvVerticalMenu_receiveKey(nvWidget * this, int ch) {
    bool rv = nvFocusManager_receiveKey(THIS(nvVerticalMenu)->focusManager, ch);

    /*
     * TODO handle remaining keys? 
     */
    return rv;
}

void nvVerticalMenu_refresh(nvWidget * this) {
    nvCursesWindow_fillBackground(this->cw, ' ');
    nvSubwidgetManager_refresh(THIS(nvVerticalMenu)->subwidgetManager);
    nvCursesWindow_refresh(this->cw);
}

bool nvVerticalMenu_focus(nvWidget * this) {
    THIS(nvVerticalMenu)->isFocused = true;
    nvFocusManager_focus(THIS(nvVerticalMenu)->focusManager);
    return true;
}

bool nvVerticalMenu_deFocus(nvWidget * this) {
    THIS(nvVerticalMenu)->isFocused = false;
    nvFocusManager_deFocus(THIS(nvVerticalMenu)->focusManager);
    return true;
}

/* DUMMY */
void nvVerticalMenu_setInputMode(nvWidget * this, nvInputMode mode) {
}
