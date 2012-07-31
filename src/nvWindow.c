#include"nvWindow.h"

static nvWindow *nvWindow__new_(int x, int y, int width, int height);

static nvWindow *nvWindow__new_(int x, int y, int width, int height) {
    nvWindow *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->focusManager = nvFocusManager__new();
        this->subwidgetManager = nvSubwidgetManager__new();
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvWindow");
}

nvWidget *nvWindow__new(int x, int y, wint width, int height) {
    nvWindow *window = nvWindow__new_(x, y, width, height);

    nvWidget *this = nvWidget__new_(x, y, width, height, (void *)window);
}
