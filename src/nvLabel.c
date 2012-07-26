#include"nvLabel.h"

nvLabel *nvLabel__new(int x, int y, cgString * text) {
    nvLabel *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->cw = nvCursesWindow__new(x, y, cgString_getSize(text), 1);
        this->text = text;
    }
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal,
                         cgExceptionID_CannotAllocate,
                         "cannot allocate nvLabel");
    return this;
}

void nvLabel_delete(nvLabel * this) {
    nvCursesWindow_delete(this->cw);
    cgString_delete(this->text);
}

void nvLabel_refresh(nvLabel * this) {
    nvCursesWindow_addString(this->cw, this->text);
}
