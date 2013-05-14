#include"nvSubwidgetManager.h"
static bool nvSubwidgetManager_widgetShouldBeDisplayed_(nvSubwidgetManager * this, nvWidget * widget);

nvSubwidgetManager *nvSubwidgetManager__new() {
    nvSubwidgetManager *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->subWidgets = cgArray__new(nvWidget, 1);
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate,
                         "cannot allocate nvSubwidgetManager");
    return this;
}
void nvSubwidgetManager_delete(nvSubwidgetManager * this) {
    cgArray_delete(nvWidget, this->subWidgets);
    free(this);
}

void nvSubwidgetManager_deleteSubwidgets(nvSubwidgetManager * this) {
    cgArray_deleteValues(nvWidget, this->subWidgets);
}

void nvSubwidgetManager_addWidget(nvSubwidgetManager * this, nvWidget * widget) {
    cgArray_add(nvWidget, this->subWidgets, widget);
}

static bool nvSubwidgetManager_widgetShouldBeDisplayed_(nvSubwidgetManager * this, nvWidget * widget) {
    return (nvWidget_getIsVisible(widget) && nvWidget_doesOverlapClientRect(nvWidget_getParent(widget), widget));
}
void nvSubwidgetManager_refresh(nvSubwidgetManager * this) {
    cgArrayIterator(nvWidget) * iter = cgArrayIterator__new(nvWidget, this->subWidgets);
    nvWidget *widget = NULL;

    nvWidget *focusedWidget = nvCursesManager_getFocusedWidget(nvCursesManager__getInstance());

    while ((widget = cgArrayIterator_fetch(nvWidget, iter)) != NULL) {
        if (widget != focusedWidget && nvSubwidgetManager_widgetShouldBeDisplayed_(this, widget))
            nvWidget_refresh(widget);
    }
    
    cgArrayIterator_reset(nvWidget, iter);
    
    while ((widget = cgArrayIterator_fetch(nvWidget, iter)) != NULL) {
        if (focusedWidget == widget && nvSubwidgetManager_widgetShouldBeDisplayed_(this, widget))
            nvWidget_refresh(focusedWidget);
    }
    
    nvCursesManager_refresh(nvCursesManager__getInstance());
}

cgArray(nvWidget) * nvSubwidgetManager_getSubWidgets(nvSubwidgetManager * this) {
    return this->subWidgets;
}
