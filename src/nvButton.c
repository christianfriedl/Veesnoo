#include"nvButton.h"

static nvButton *nvButton__new_(int x, int y, cgString * text);

static nvButton *nvButton__new_(int x, int y, cgString * text) {
    nvButton *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->text = text;
        this->isFocused = false;
        this->onPushMethod = NULL;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate,
                         "cannot allocate nvButton");
    return this;
}

nvWidget *nvButton__new(int x, int y, cgString * text) {
    nvWidget *this = nvWidget__new_(nvWidgetType_actionLabel, x, y, cgString_getByteSize(text) + 4, 1,
                                    nvButton__new_(x, y, text));

    nvWidget_setRefreshMethod(this, nvButton_refresh);
    nvWidget_setReceiveKeyMethod(this, nvButton_receiveKey);
    nvWidget_setFocusMethod(this, nvButton_focus);
    nvWidget_setDefocusMethod(this, nvButton_deFocus);
    this->setInputModeMethod = nvButton_setInputMode;

    return this;
}

void nvButton_delete(nvWidget * this) {
    nvWidget_delete_(this);
    cgString_delete(THIS(nvButton)->text);
}

void nvButton_setText(nvWidget * this, cgString * text) {
    cgString_delete(THIS(nvButton)->text);
    THIS(nvButton)->text = text;
}

void nvButton_refresh(nvWidget * this) {
    if (THIS(nvButton)->isFocused == true)
        nvCursesWindow_attrOn(this->cw, A_REVERSE);

    nvCursesWindow_addChAt(this->cw, 0, 0, '[');
    nvCursesWindow_addStringAt(this->cw, 2, 0, THIS(nvButton)->text);
    nvCursesWindow_addChAt(this->cw, nvCursesWindow_getWidth(this->cw) - 1, 0, ']');

    if (THIS(nvButton)->isFocused == true)
        nvCursesWindow_attrOff(this->cw, A_REVERSE);

    nvCursesWindow_refresh(this->cw);
}

bool nvButton_receiveKey(nvWidget * this, int ch) {
    bool rv;

    if (THIS(nvButton)->isFocused == true) {
        switch (ch) {
        case NV_ENTER:
        case ' ':
            rv = true;
            nvButton_push(this);
            break;
        default:
            rv = false;
        }
    } else
        rv = false;
    nvButton_refresh(this);
    return rv;
}

cgString *nvButton_getText(nvWidget * this) {
    return THIS(nvButton)->text;
}

bool nvButton_getIsFocused(nvWidget * this) {
    return THIS(nvButton)->isFocused;
}

bool nvButton_focus(nvWidget * this) {
    THIS(nvButton)->isFocused = true;
    return true;
}

bool nvButton_deFocus(nvWidget * this) {
    THIS(nvButton)->isFocused = false;
    return true;
}

void nvButton_setOnPushMethod(nvWidget* this, void(*method)(nvWidget*)) {
    THIS(nvButton)->onPushMethod = method;
}

void nvButton_push(nvWidget * this) {
    if (THIS(nvButton)->onPushMethod != NULL)
        (THIS(nvButton)->onPushMethod)(this);
}
/* DUMMY */
void nvButton_setInputMode(nvWidget * this, nvInputMode mode) {
}
