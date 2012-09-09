#include<cgenerics/cgRectangle.h>
#include"nvHorizontalMenu.h"

static nvHorizontalMenu *nvHorizontalMenu__new_(int x, int y);

static nvHorizontalMenu *nvHorizontalMenu__new_(int x, int y) {
    nvHorizontalMenu *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->focusManager = nvFocusManager__new();
        this->subwidgetManager = nvSubwidgetManager__new();
        this->isFocused = false;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate,
                         "cannot allocate nvHorizontalMenu");
    return this;
}

nvWidget *nvHorizontalMenu__new(int x, int y) {
    nvHorizontalMenu *menu = nvHorizontalMenu__new_(x, y);

    nvWidget *this = nvWidget__new_(nvWidgetType_horizontalMenu, x, y, 0, 1, (void *)menu);

    nvWidget_setRefreshMethod(this, nvHorizontalMenu_refresh);
    nvWidget_setReceiveKeyMethod(this, nvHorizontalMenu_receiveKey);
    nvWidget_setFocusMethod(this, nvHorizontalMenu_focus);
    nvWidget_setDefocusMethod(this, nvHorizontalMenu_deFocus);
    this->setInputModeMethod = nvHorizontalMenu_setInputMode;

    return this;
}

void nvHorizontalMenu_delete(nvWidget * this) {
    nvFocusManager_delete(THIS(nvHorizontalMenu)->focusManager);
    nvSubwidgetManager_delete(THIS(nvHorizontalMenu)->subwidgetManager);
    nvWidget_delete_(this);
}

void nvHorizontalMenu_addWidget(nvWidget * this, nvWidget * widget) {
    /*
     * move relative to absolute coordinates 
     */
    cgArray(nvWidget) * sw = nvSubwidgetManager_getSubWidgets(THIS(nvHorizontalMenu)->subwidgetManager);
    int x = 0;
    if (cgArray_getSize(nvWidget, sw) > 0) {
        nvWidget *lastItem = NULL;
        lastItem = cgArray_getValueAt(nvWidget, sw, cgArray_getSize(nvWidget, sw) - 1);
        x = nvWidget_getX(lastItem) + nvWidget_getWidth(lastItem) + 1;
    }
    nvWidget_move(widget, x, nvWidget_getY(this));
    nvFocusManager_addWidget(THIS(nvHorizontalMenu)->focusManager, widget);
    /*
     * resize menu to accomodate widget 
     */
    nvWidget_resize(this, nvWidget_getX(widget) + nvWidget_getWidth(widget) - this->x, 1);
    nvWidget_setParent(widget, this);
    nvSubwidgetManager_addWidget(THIS(nvHorizontalMenu)->subwidgetManager, widget);
}

bool nvHorizontalMenu_receiveKey(nvWidget * this, int ch) {
    bool rv = nvFocusManager_receiveKey(THIS(nvHorizontalMenu)->focusManager, ch);

    /*
     * TODO handle remaining keys? 
     */
    return rv;
}

void nvHorizontalMenu_refresh(nvWidget * this) {
    nvSubwidgetManager_refresh(THIS(nvHorizontalMenu)->subwidgetManager);
    nvCursesWindow_refresh(this->cw);
}

bool nvHorizontalMenu_focus(nvWidget* this) {
    THIS(nvHorizontalMenu)->isFocused = true;
    nvFocusManager_focus(THIS(nvHorizontalMenu)->focusManager);
    return true;
}

bool nvHorizontalMenu_deFocus(nvWidget* this) {
    THIS(nvHorizontalMenu)->isFocused = false;
    nvFocusManager_deFocus(THIS(nvHorizontalMenu)->focusManager);
    return true;
}

/* DUMMY */
void nvHorizontalMenu_setInputMode(nvWidget * this, nvInputMode mode) {
}
