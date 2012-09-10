#include<cgenerics/cgRectangle.h>
#include"nvPopupMenu.h"

static nvPopupMenu *nvPopupMenu__new_(int x, int y);

static nvPopupMenu *nvPopupMenu__new_(int x, int y) {
    nvPopupMenu *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->window = nvWindow__new(x, y, 1, 1);
        nvWindow_setResizeMode(this->window, nvWindowResizeMode_fromChildren);
        this->menu = nvVerticalMenu__new(0, 0);
        nvWindow_addWidget(this->window, this->menu);
        nvWindow_hide(this->window);
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvPopupMenu");
    return this;
}

nvWidget *nvPopupMenu__new(int x, int y) {
    nvPopupMenu *menu = nvPopupMenu__new_(x, y);

    nvWidget *this = nvWidget__new_(nvWidgetType_popupMenu, x, y, 0, 0, (void *)menu);

    nvWidget_setRefreshMethod(this, nvPopupMenu_refresh);
    nvWidget_setReceiveKeyMethod(this, nvPopupMenu_receiveKey);
    nvWidget_setDoesOverlapClientRectMethod(this, nvPopupMenu_doesOverlapClientRect);
    nvWidget_setFocusMethod(this, nvPopupMenu_focus);
    nvWidget_setDefocusMethod(this, nvPopupMenu_deFocus);

    return this;
}

void nvPopupMenu_delete(nvWidget * this) {
    nvWindow_delete(THIS(nvPopupMenu)->window);
    nvVerticalMenu_delete(THIS(nvPopupMenu)->menu);
    nvWidget_delete_(this);
}

void nvPopupMenu_addWidget(nvWidget * this, nvWidget * widget) {
    nvVerticalMenu_addWidget(THIS(nvPopupMenu)->menu, widget);
    nvWindow_pack(THIS(nvPopupMenu)->window);
}

bool nvPopupMenu_receiveKey(nvWidget * this, int ch) {
    bool rv = nvWidget_receiveKey(THIS(nvPopupMenu)->window, ch);

    /*
     * TODO handle remaining keys? 
     */
    return rv;
}

void nvPopupMenu_refresh(nvWidget * this) {
    if (cgArray_getSize(nvWidget, nvSubwidgetManager_getSubWidgets(nvVerticalMenu_getSubwidgetManager(THIS(nvPopupMenu)->menu))) >
        0) {
        nvWidget_refresh(THIS(nvPopupMenu)->window);
    }
}

bool nvPopupMenu_doesOverlapClientRect(nvWidget * this, nvWidget * that) {
    return nvWidget_doesOverlapClientRect(THIS(nvPopupMenu)->window, that);
}

bool nvPopupMenu_focus(nvWidget * this) {
    nvWidget_focus(THIS(nvPopupMenu)->window);
}

bool nvPopupMenu_deFocus(nvWidget * this) {
    nvWidget_deFocus(THIS(nvPopupMenu)->window);
}

void nvPopupMenu_show(nvWidget * this) {
    nvWindow_show(THIS(nvPopupMenu)->window);
}

void nvPopupMenu_hide(nvWidget * this) {
    nvWindow_hide(THIS(nvPopupMenu)->window);
}
