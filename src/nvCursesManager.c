#include"nvCursesManager.h"

static nvCursesManager *nvCursesManager__instance_ = NULL;

static nvCursesManager *nvCursesManager__new_() {
    nvCursesManager *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->bufferedMode = false;
        this->echo = false;
        this->keypadAvailable = true;
        this->width = 0;
        this->height = 0;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal,
                         cgExceptionID_CannotAllocate, "cannot allocate nvCursesManager");
    return this;
}

nvCursesManager *nvCursesManager__getInstance() {
    if (nvCursesManager__instance_ == NULL)
        nvCursesManager__instance_ = nvCursesManager__new_();
    return nvCursesManager__instance_;
}

void nvCursesManager_delete(nvCursesManager * this) {
    free(this);
    nvCursesManager__instance_ = NULL;
}

void nvCursesManager_initCurses(nvCursesManager * this) {
    initscr();
    getmaxyx(stdscr, this->height, this->width);
    if (!this->bufferedMode) {
        raw();
        cbreak();
    }
    if (!this->echo) {
        noecho();
    }
    if (this->keypadAvailable) {
        keypad(stdscr, TRUE);
        set_escdelay(25);       /* set ESC delay to a very low level so we can use the ESC key AND the function keys ('tis good enough for VIM, 'tis good enough for me) */
    }
    if (has_colors())
        start_color();
    else
        cgAppState_THROW(cgAppState__getInstance(), Severity_warning, nvExceptionID_nonfatalException,
                         "this terminal has no colors.");
}

void nvCursesManager_uninitCurses(nvCursesManager * this) {
    endwin();
}

WINDOW *nvCursesManager_createWindow(nvCursesManager * this, int x, int y, int width, int height) {
    return newwin(height, width, y, x);
}

void nvCursesManager_destroyWindow(nvCursesManager * this, WINDOW * window) {
    delwin(window);
}

void nvCursesManager_refresh(nvCursesManager * this) {
    doupdate();
}

void nvCursesManager_clearScreen(nvCursesManager * this) {
    erase();
    refresh();
}

int nvCursesManager_getScreenWidth(nvCursesManager * this) {
    return this->width;
}

int nvCursesManager_getScreenHeight(nvCursesManager * this) {
    return this->height;
}
