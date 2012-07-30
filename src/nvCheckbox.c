#include"nvCheckbox.h"

static nvCheckbox *nvCheckbox__new_(bool value);

static nvCheckbox *nvCheckbox__new_(bool value) {
    nvCheckbox *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->value = value;
        this->inputMode = nvInputMode_command;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvCheckbox");
    return this;
}

nvWidget *nvCheckbox__new(int x, int y, bool value) {
    nvWidget *this = nvWidget__new_(nvWidgetType_checkbox, x, y, 3, 1,
                                    nvCheckbox__new_(value));

    nvWidget_setRefresh(this, (void (*)(nvWidget *))nvCheckbox_refresh);
    nvWidget_setReceiveKey(this, (bool(*)(nvWidget *, int))nvCheckbox_receiveKey);
    this->funcSetInputMode = nvCheckbox_setInputMode;
    return this;
}

void nvCheckbox_delete(nvWidget * this) {
    nvWidget_delete_(this);
    free(THIS(nvCheckbox));
}

void nvCheckbox_setInputMode(nvWidget * this, nvInputMode mode) {
    THIS(nvCheckbox)->inputMode = mode;
    nvCheckbox_refresh(this);
}

void nvCheckbox_setValue(nvWidget * this, bool value) {
    THIS(nvCheckbox)->value = value;
    nvCheckbox_refresh(this);
}

void nvCheckbox_refresh(nvWidget * this) {
    if (THIS(nvCheckbox)->inputMode == nvInputMode_command)
        nvCursesWindow_attrOn(this->cw, A_REVERSE);

    cgString *text = cgString__newWithSprintf("[%c]", (THIS(nvCheckbox)->value ? 'x' : ' '));

    nvCursesWindow_addStringAt(this->cw, 0, 0, text);
    
    cgString_delete(text);

    if (THIS(nvCheckbox)->inputMode == nvInputMode_command)
        nvCursesWindow_attrOff(this->cw, A_REVERSE);
    
    nvCursesWindow_moveCursorTo(this->cw, 1, 0);
    nvCursesWindow_refresh(this->cw);
}

bool nvCheckbox_receiveKey(nvWidget * this, int ch) {
    bool rv;

    if (THIS(nvCheckbox)->inputMode == nvInputMode_command) {
        switch (ch) {
            case NV_ENTER:
            case ' ':
            case 'x':
                THIS(nvCheckbox)->value = (THIS(nvCheckbox)->value == true ? false : true);
                rv = true;
                break;
            default:
                rv = false;
        }
    }
    nvCheckbox_refresh(this);
    return rv;
}

bool nvCheckbox_getValue(nvWidget * this) {
    return THIS(nvCheckbox)->value;
}
