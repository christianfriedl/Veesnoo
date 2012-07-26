#include"nvColorManager.h"

static nvColorManager *nvColorManager__instance_ = NULL;

static nvColorManager *nvColorManager__new_() {
    nvColorManager *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->nextPair = 1;
    }
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal,
                         cgExceptionID_CannotAllocate,
                         "cannot allocate nvColorManager");
    return this;
}

nvColorManager *nvColorManager__getInstance() {
    if (nvColorManager__instance_ == NULL)
        nvColorManager__instance_ = nvColorManager__new_();
    return nvColorManager__instance_;
}

void nvColorManager_delete(nvColorManager * this) {
    free(this);
    nvColorManager__instance_ = NULL;
}

int nvColorManager_createColor(nvColorManager* this, short fg, short bg) {
    if (this->nextPair > COLOR_PAIRS) {
        cgAppState_THROW(cgAppState__getInstance(), Severity_error, cgExceptionID_GeneralNonfatalException, "cannot create a new color pair, starting over with first pair");
        this->nextPair = 1;
    }
    init_pair(this->nextPair, fg, bg);
    return this->nextPair++;
}
