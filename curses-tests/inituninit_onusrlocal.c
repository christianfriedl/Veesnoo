#include<ncurses/ncurses.h>

int main() {
    initscr();
    WINDOW *win = newwin(10, 10, 2, 2);
    delwin(win);
    endwin();
    return 0;
}
