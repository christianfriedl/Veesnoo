#include<ncursesw/ncurses.h>
int main() {
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    int have_pressed_cc = 0;
    do {
        char msg[255];
        int ch = getch(); 
        sprintf(msg, "KEY NAME : %s - %d\n", keyname(ch),ch);
        attron(A_DIM);
        addstr(msg);
        attroff(A_DIM);
        if ( ch == 3 ) {
            have_pressed_cc++;
            sprintf(msg, "you have pressed ctrl-c %i times now, 2 times will terminate\n", have_pressed_cc);
            addstr(msg);
        }
    } while (have_pressed_cc < 2);
    endwin(); 
}
