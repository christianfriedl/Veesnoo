#include "ncursesw/ncurses.h"

int main() {
    int width, height;
    initscr();
    getmaxyx(stdscr, height, width);
    raw();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    set_escdelay(25);
    start_color();

    WINDOW *win1 = newwin(10, 10, 10, 10);
    mvwaddnstr(win1, 0, 0, "ein text", 5);
    WINDOW *win2 = newwin(30, 40, 0, 0);
    box(win2, 0, 0);
    refresh();
    wrefresh(win2);
    refresh();
    wrefresh(win1);
    refresh();
    wmove(win1, 0, 2);
    refresh();
    wrefresh(win1);
    getch();
    endwin();

}
