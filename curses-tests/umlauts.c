#include<ncursesw/ncurses.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    int have_pressed_cc = 0;
    do {
        char msg[255];
        int ch = getch(); 
        sprintf(msg, "testing testing... äöü\n");
        if ( ch == '0' ) curs_set(0);
        if ( ch == '1' ) curs_set(1);
        if ( ch == '2' ) curs_set(2);
        addstr(msg);
        if ( ch == 3 ) {
            have_pressed_cc++;
            sprintf(msg, "you have pressed ctrl-c %i times now, 2 times will terminate\n", have_pressed_cc);
            addstr(msg);
        }
    } while (have_pressed_cc < 2);
    endwin(); 
}
