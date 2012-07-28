#include"nvLabel.h"

static nvLabel *nvLabel__new_(int x, int y, cgString * text) {
    nvLabel *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->text = text;
    }
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal,
                         cgExceptionID_CannotAllocate,
                         "cannot allocate nvLabel");
    return this;
}

nvWidget *nvLabel__new(int x, int y, cgString * text) {
    nvWidget *this =
        nvWidget__new_(nvWidgetType_label, x, y, cgString_getSize(text), 1,
                      nvLabel__new_(x, y, text));
    nvWidget_setRefresh(this, (void(*)(void*))nvLabel_refresh);
    return this;
}

void nvLabel_setText(nvWidget* this, cgString* text) {
    cgString_delete(((nvLabel*)(this->data))->text);
    ((nvLabel*)(this->data))->text = text;
    nvWidget_resize(this, cgString_getSize(text), 1);
    nvLabel_refresh(this);
}

void nvLabel_delete(nvWidget * this) {
    nvWidget_delete_(this);
    cgString_delete(((nvLabel*)(this->data))->text);
}

void nvLabel_refresh(nvWidget * this) {
    nvCursesWindow_addStringAt(this->cw, 0, 0, ((nvLabel*)(this->data))->text);
    nvCursesWindow_refresh(this->cw);
}
