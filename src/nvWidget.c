#include"nvWidget.h"

nvWidget* nvWidget__new(nvWidgetType type, int x, int y, int width, int height, void* data) {
    nvWidget* this = malloc(sizeof(*this));
    if (this != NULL) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->cw = nvCursesWindow__new(x, y, width, height);
        this->data = data;
        this->type = type;
        this->refresh = NULL;
        this->move = NULL;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvWidget");
    return this;
}

void nvWidget_setRefresh(nvWidget* this, void(*refresh)(void*)) {
    this->refresh = refresh;
}

void nvWidget_setMove(nvWidget* this, void(*move)(void*)) {
    this->move = move;
}

void nvWidget_delete(nvWidget* this) {
    free(this);
}

void nvWidget_refresh(nvWidget* this) {
    (this->refresh)(this);
}
