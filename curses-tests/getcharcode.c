#include<ncursesw/ncurses.h>
int main() {
    initscr();
    noecho();
    keypad(NULL, TRUE);
    do {
        char msg[30];
        int ch = getch(); 
        sprintf(msg, "KEY NAME : %s - %d\n", keyname(ch),ch);
        addstr(msg);
    } while (1);
    endwin(); 
}
