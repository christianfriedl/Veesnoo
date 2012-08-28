#include"nvFocusManager.h"

static nvWidget *nvFocusManager_findNextWidget_(nvFocusManager * this);

nvFocusManager *nvFocusManager__new() {
    nvFocusManager *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->widgets = cgArray__new(nvWidget, 1);
        this->focusedWidget = NULL;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate,
                         "unable to allocate nvFocusManager");
    return this;
}

void nvFocusManager_delete(nvFocusManager * this) {
    cgArray_delete(nvWidget, this->widgets);
    free(this);
}

static int compareWidgets_(const nvWidget ** w1, const nvWidget ** w2) {
    nvWidget *ww1 = *(nvWidget **) w1;

    nvWidget *ww2 = *(nvWidget **) w2;

    return (ww1 == ww2 ? 0 : 1);    /* widgets are uncloneable - possible TODO to change that */
}

static nvWidget *nvFocusManager_findNextWidget_(nvFocusManager * this) {
    unsigned int index = 0;

    index = cgArray_findIndex(nvWidget, this->widgets, this->focusedWidget, compareWidgets_);
    if (index == cgArray_getSize(nvWidget, this->widgets) - 1)
        return cgArray_getValueAt(nvWidget, this->widgets, 0);
    else
        return cgArray_getValueAt(nvWidget, this->widgets, index + 1);
}

bool nvFocusManager_receiveKey(nvFocusManager * this, int ch) {
    if (this->focusedWidget == NULL)
        if (cgArray_getSize(nvWidget, this->widgets) != 0)
            this->focusedWidget = cgArray_getValueAt(nvWidget, this->widgets, 0);

    if (this->focusedWidget != NULL) {
        bool rv = nvWidget_receiveKey(this->focusedWidget, ch);

        if (rv == false) {
            switch (ch) {
            case NV_TAB:
                nvWidget_setInputMode(this->focusedWidget, nvInputMode_none);
                this->focusedWidget = nvFocusManager_findNextWidget_(this);
                nvWidget_setInputMode(this->focusedWidget, nvInputMode_command);
                return true;
                break;
            }
        }
    } else
        return false;
}

void nvFocusManager_addWidget(nvFocusManager * this, nvWidget * widget) {
    cgArray_add(nvWidget, this->widgets, widget);
}

nvWidget *nvFocusManager_getFocusedWidget(nvFocusManager * this) {
    return this->focusedWidget;
}
