#include"nvTextbox.h"
static nvTextbox *nvTextbox__new_(int x, int y, cgString * text);
static void nvTextbox_insertChar_(nvWidget* this, char ch);

static nvTextbox *nvTextbox__new_(int x, int y, cgString * text) {
    nvTextbox *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->text = text;
        this->inputMode = nvInputMode_command;
        this->cursorPos = 0;
    }
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal,
                         cgExceptionID_CannotAllocate,
                         "cannot allocate nvTextbox");
    return this;
}

nvWidget *nvTextbox__new(int x, int y, cgString * text) {
    nvWidget *this =
        nvWidget__new_(nvWidgetType_label, x, y, cgString_getSize(text), 1,
                      nvTextbox__new_(x, y, text));
    nvWidget_setRefresh(this, (void(*)(nvWidget*))nvTextbox_refresh);
    nvWidget_setReceiveKey(this, (void(*)(nvWidget*,char))nvTextbox_receiveKey);
    return this;
}

static void nvTextbox_insertChar_(nvWidget* this, char ch) {
    if (THIS(nvTextbox)->cursorPos == cgString_getSize(THIS(nvTextbox)->text))
        THIS(nvTextbox)->text = cgString_appendChar_I(THIS(nvTextbox)->text, ch);
    else
        THIS(nvTextbox)->text = cgString_insertChar_I(THIS(nvTextbox)->text, THIS(nvTextbox)->cursorPos, ch);
    THIS(nvTextbox)->cursorPos++;
}

void nvTextbox_delete(nvWidget * this) {
    nvWidget_delete_(this);
    cgString_delete(((nvTextbox*)(this->data))->text);
}

void nvTextbox_setInputMode(nvWidget* this, nvInputMode mode) {
    THIS(nvTextbox)->inputMode = mode;
    nvTextbox_refresh(this);
}

void nvTextbox_setText(nvWidget* this, cgString* text) {
    cgString_delete(THIS(nvTextbox)->text);
    THIS(nvTextbox)->text = text;
    nvTextbox_refresh(this);
}

void nvTextbox_refresh(nvWidget * this) {
    nvCursesWindow_addStringAt(this->cw, 0, 0, ((nvTextbox*)(this->data))->text);
}

void nvTextbox_receiveKey(nvWidget * this, char ch) {
    if (THIS(nvTextbox)->inputMode == nvInputMode_insert)
        nvTextbox_insertChar_(this, ch);
    nvTextbox_refresh(this);
}
