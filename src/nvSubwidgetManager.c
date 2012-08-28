#include"nvSubwidgetManager.h"

nvSubwidgetManager* nvSubwidgetManager__new() {
    nvSubwidgetManager* this = malloc(sizeof(*this));
    if (this != NULL) {
        this->subWidgets = cgArray__new(nvWidget, 1);
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvSubwidgetManager");
    return this;
}
void nvSubwidgetManager_delete(nvSubwidgetManager* this) { 
    cgArray_delete(nvWidget, this->subWidgets);
    free(this);
}

void nvSubwidgetManager_addWidget(nvSubwidgetManager* this, nvWidget* widget) {
    cgArray_add(nvWidget, this->subWidgets, widget);
}

void nvSubwidgetManager_refresh(nvSubwidgetManager* this) {
    cgArrayIterator(nvWidget)* iter = cgArrayIterator__new(nvWidget, this->subWidgets);
    nvWidget* widget = NULL;
    nvWidget* focusedWidget = nvCursesManager_getFocusedWidget(nvCursesManager__getInstance());
    while  ((widget = cgArrayIterator_fetch(nvWidget, iter)) != NULL) {
         if (widget != focusedWidget)
            nvWidget_refresh(widget);
    }
    if (focusedWidget != NULL)
        nvWidget_refresh(focusedWidget);
    nvCursesManager_refresh(nvCursesManager__getInstance());
}
