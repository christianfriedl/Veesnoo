 #include <ncurses/curses.h>

/*
WINDOW *initscr(void);
int endwin(void);
bool isendwin(void);
SCREEN *newterm(char *type, FILE *outfd, FILE *infd);
SCREEN *set_term(SCREEN *new);
void delscreen(SCREEN* sp);
*/

int main() {
    SCREEN *s1 = newterm(NULL, ofd, ifd);
}

