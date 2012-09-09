#include"nvActionLabel.h"

static nvActionLabel *nvActionLabel__new_(int x, int y, cgString * text);

static nvActionLabel *nvActionLabel__new_(int x, int y, cgString * text) {
    nvActionLabel *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->text = text;
        this->isFocused = false;
        this->onPushMethod = NULL;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate,
                         "cannot allocate nvActionLabel");
    return this;
}

nvWidget *nvActionLabel__new(int x, int y, cgString * text) {
    nvWidget *this = nvWidget__new_(nvWidgetType_actionLabel, x, y, cgString_getByteSize(text), 1,
                                    nvActionLabel__new_(x, y, text));

    nvWidget_setRefreshMethod(this, nvActionLabel_refresh);
    nvWidget_setReceiveKeyMethod(this, nvActionLabel_receiveKey);
    nvWidget_setFocusMethod(this, nvActionLabel_focus);
    nvWidget_setDefocusMethod(this, nvActionLabel_deFocus);
    this->setInputModeMethod = nvActionLabel_setInputMode;

    return this;
}

void nvActionLabel_delete(nvWidget * this) {
    nvWidget_delete_(this);
    cgString_delete(THIS(nvActionLabel)->text);
}

void nvActionLabel_setText(nvWidget * this, cgString * text) {
    cgString_delete(THIS(nvActionLabel)->text);
    THIS(nvActionLabel)->text = text;
    nvActionLabel_refresh(this);
}

void nvActionLabel_refresh(nvWidget * this) {
    if (THIS(nvActionLabel)->isFocused == true)
        nvCursesWindow_attrOn(this->cw, A_REVERSE);

    nvCursesWindow_addStringAt(this->cw, 0, 0, THIS(nvActionLabel)->text);

    if (THIS(nvActionLabel)->isFocused == true)
        nvCursesWindow_attrOff(this->cw, A_REVERSE);

    nvCursesWindow_refresh(this->cw);
}

bool nvActionLabel_receiveKey(nvWidget * this, int ch) {
    bool rv;

    if (THIS(nvActionLabel)->isFocused == true) {
        switch (ch) {
        case NV_ENTER:
        case ' ':
            rv = true;
            nvActionLabel_push(this);
            break;
        default:
            rv = false;
        }
    } else
        rv = false;
    nvActionLabel_refresh(this);
    return rv;
}

cgString *nvActionLabel_getText(nvWidget * this) {
    return THIS(nvActionLabel)->text;
}

bool nvActionLabel_getIsFocused(nvWidget * this) {
    return THIS(nvActionLabel)->isFocused;
}

bool nvActionLabel_focus(nvWidget * this) {
    THIS(nvActionLabel)->isFocused = true;
    return true;
}

bool nvActionLabel_deFocus(nvWidget * this) {
    THIS(nvActionLabel)->isFocused = false;
    return true;
}

void nvActionLabel_setOnPushMethod(nvWidget* this, void(*method)(nvWidget*)) {
    THIS(nvActionLabel)->onPushMethod = method;
}

void nvActionLabel_push(nvWidget * this) {
    if (THIS(nvActionLabel)->onPushMethod != NULL)
        (THIS(nvActionLabel)->onPushMethod)(this);
}
/* DUMMY */
void nvActionLabel_setInputMode(nvWidget * this, nvInputMode mode) {
}
