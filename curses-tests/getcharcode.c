#include<ncursesw/ncurses.h>
int main() {
    initscr();
    int ch = getch(); 
    endwin(); 
    printf("KEY NAME : %s - %d\n", keyname(ch),ch);
}
