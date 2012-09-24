#include<cgenerics/cgRectangle.h>
#include"nvSelectbox.h"

static nvSelectbox *nvSelectbox__new_(int x, int y);
static nvSelectbox *nvSelectbox__newWithLabels_(int x, int y, cgArray(cgString)* labels);
static void nvSelectbox_itemPushed_(nvWidget * item, void * selectbox);

static nvSelectbox *nvSelectbox__new_(int x, int y) {
    nvSelectbox *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->label = nvActionLabel__new(x, y, cgString__new(""));
        this->menu = nvPopupMenu__new(max(0, x - 1), y + 1); // TODO check whether we have enough space below the label
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvSelectbox");
    return this;
}

static nvSelectbox *nvSelectbox__newWithLabels_(int x, int y, cgArray(cgString)* labels) {
    nvSelectbox *this = nvSelectbox__new_(x, y);
    cgArrayIterator(cgString)* iter = cgArrayIterator__new(cgString, labels);
    cgString* label = NULL;
    while ((label = cgArrayIterator_fetch(cgString, iter)) != NULL) {
        nvWidget* item = nvActionLabel__new(0, 0, label);
        nvPopupMenu_addWidget(this->menu, item);
        nvActionLabel_setOnPushMethod(item, nvSelectbox_itemPushed_, (void*)this);
    }
    return this;
}

nvWidget *nvSelectbox__new(int x, int y) {
    nvSelectbox *selectbox = nvSelectbox__new_(x, y);

    nvWidget *this = nvWidget__new_(nvWidgetType_selectbox, x, y, 0, 0, (void *)selectbox);

    nvWidget_setRefreshMethod(this, nvSelectbox_refresh);
    nvWidget_setReceiveKeyMethod(this, nvSelectbox_receiveKey);
    nvWidget_setFocusMethod(this, nvSelectbox_focus);
    nvWidget_setDefocusMethod(this, nvSelectbox_deFocus);

    return this;
}

nvWidget *nvSelectbox__newWithLabels(int x, int y, cgArray(cgString)* labels) {
    nvSelectbox *selectbox = nvSelectbox__newWithLabels_(x, y, labels);

    nvWidget *this = nvWidget__new_(nvWidgetType_selectbox, x, y, 0, 0, (void *)selectbox);

    nvWidget_setRefreshMethod(this, nvSelectbox_refresh);
    nvWidget_setReceiveKeyMethod(this, nvSelectbox_receiveKey);
    nvWidget_setFocusMethod(this, nvSelectbox_focus);
    nvWidget_setDefocusMethod(this, nvSelectbox_deFocus);


    return this;
}

void nvSelectbox_delete(nvWidget * this) {
    nvActionLabel_delete(THIS(nvSelectbox)->label);
    nvPopupMenu_delete(THIS(nvSelectbox)->menu);
    nvWidget_delete_(this);
}

void nvSelectbox_addItem(nvWidget * this, cgString * label) {
    nvWidget* item = nvActionLabel__new(0, 0, label);
    nvPopupMenu_addWidget(THIS(nvSelectbox)->menu, item);
    nvActionLabel_setOnPushMethod(item, nvSelectbox_itemPushed_, (void*)this);
}

bool nvSelectbox_receiveKey(nvWidget * this, int ch) {
    bool rv;
    if (nvActionLabel_getIsFocused(THIS(nvSelectbox)->label) == true) {
        rv = nvWidget_receiveKey(THIS(nvSelectbox)->label, ch);
        if (rv == false) {
            switch(ch) {
                case KEY_UP:
                case KEY_DOWN:
                case NV_ENTER:
                    rv = true;
                    nvWidget_deFocus(THIS(nvSelectbox)->label);
                    nvWidget_focus(THIS(nvSelectbox)->menu);
                    break;
            }
        }
    } else if (nvPopupMenu_getIsFocused(THIS(nvSelectbox)->menu) == true) {
        rv = nvWidget_receiveKey(THIS(nvSelectbox)->menu, ch);
    } else {
        cgAppState_THROW(cgAppState__getInstance(), Severity_error, nvExceptionID_nonfatalException, "selectbox received key, but no subwidget is focused.");
        rv = false;
    }

    return rv;
}

void nvSelectbox_refresh(nvWidget * this) {
    nvWidget_refresh(THIS(nvSelectbox)->label);
    nvWidget_refresh(THIS(nvSelectbox)->menu);
}

bool nvSelectbox_focus(nvWidget * this) {
    nvPopupMenu_show(THIS(nvSelectbox)->menu);
    return nvWidget_focus(THIS(nvSelectbox)->label);
}

bool nvSelectbox_deFocus(nvWidget * this) {
    nvWidget_deFocus(THIS(nvSelectbox)->label);
    nvWidget_deFocus(THIS(nvSelectbox)->menu);
    nvPopupMenu_hide(THIS(nvSelectbox)->menu);
}

void nvSelectbox_itemPushed_(nvWidget * item, void * selectbox) {
    mvaddstr(19, 20, "itemPushed");
    nvWidget * this = (nvWidget*) selectbox;
    nvActionLabel_setText(THIS(nvSelectbox)->label, cgString__new(nvActionLabel_getText(item)));
    nvActionLabel_refresh(THIS(nvSelectbox)->label);
    mvaddstr(20, 20, nvActionLabel_getText(item));
}

