#include<stdarg.h>
#include"nvCursesManager.h"

void printStatus(cgString* msg, ...) {
    va_list ap;
    int x, y, maxx;
    va_start(ap, msg);
    char * text;
    vasprintf(&text, msg, ap);
    va_end(ap);
    maxx = nvCursesManager_getScreenWidth(nvCursesManager__getInstance());
    wattron(stdscr, A_REVERSE);
    for (x=0; x < maxx; ++x)
        mvwaddch(stdscr, 0, x, ' ');
    refresh();
    mvwaddstr(stdscr, 0, 0, text);
    wattroff(stdscr, A_REVERSE);
    free(text);
    refresh();
}
void printMessage(cgString* msg, ...) {
    va_list ap;
    int x, y, maxx;
    va_start(ap, msg);
    char * text;
    vasprintf(&text, msg, ap);
    va_end(ap);
    y = nvCursesManager_getScreenHeight(nvCursesManager__getInstance()) - 1;
    maxx = nvCursesManager_getScreenWidth(nvCursesManager__getInstance());
    wattron(stdscr, A_REVERSE);
    for (x=0; x < maxx; ++x)
        mvwaddch(stdscr, y, x, ' ');
    refresh();
    mvwaddstr(stdscr, y, 0, text);
    wattroff(stdscr, A_REVERSE);
    free(text);
    refresh();
}
