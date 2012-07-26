#include"nvCursesManager.h"

static nvCursesManager *nvCursesManager__instance_ = NULL;

static nvCursesManager *
nvCursesManager__new_()
{
	nvCursesManager *this = malloc(sizeof(*this));

	if (this != NULL) {
		this->bufferedMode = false;
		this->echo = false;
		this->maxX = 0;
		this->maxY = 0;
	} else
		CGAppState_THROW(CGAppState__getInstance(), Severity_fatal, CGExceptionID_CannotAllocate, "cannot allocate nvCursesManager");
	return this;
}

nvCursesManager *
nvCursesManager__getInstance()
{
	if (nvCursesManager__instance_ == NULL)
		nvCursesManager__instance_ = nvCursesManager__new_();
	return nvCursesManager__instance_;
}

void
nvCursesManager_delete(nvCursesManager * this)
{
	free(this);
    nvCursesManager__instance_ = NULL;
}

void
nvCursesManager_initCurses(nvCursesManager * this)
{
	initscr();
	getmaxyx(stdscr, this->maxY, this->maxX);
	keypad(stdscr, TRUE);
	if (!this->bufferedMode) {
		raw();
		cbreak();
	}
	if (!this->echo) {
		noecho();
	}
	refresh();
}

void
nvCursesManager_uninitCurses(nvCursesManager * this)
{
	endwin();
}

WINDOW* nvCursesManager_createWindow(nvCursesManager* this, int x, int y, int width, int height) {
    return newwin(height, width, y, x);
}

void nvCursesManager_destroyWindow(nvCursesManager* this, WINDOW* window) {
    delwin(window);
}

void nvCursesManager_addBorder(nvCursesManager* this, WINDOW* win) {
    box(win, 0, 0);
    wnoutrefresh(win);
}

void nvCursesManager_addString(nvCursesManager* this, WINDOW* win, CGString* text) {
    waddstr(win, text);
    wnoutrefresh(win);
}

void nvCursesManager_refresh(nvCursesManager* this) {
    doupdate();
}

void nvCursesManager_clearScreen(nvCursesManager* this) {
    erase();
    refresh();
}
