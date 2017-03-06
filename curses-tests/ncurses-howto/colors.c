#include<stdlib.h>
#include<string.h>
#include <ncursesw/ncurses.h>

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
int main(int argc, char *argv[])
{	initscr();			/* Start curses mode 		*/
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();			/* Start color 			*/
     printw("can change color %i\n", can_change_color());
     printw("color return %i", init_color(COLOR_RED, 0, 20, 0)); // hmmm
     printw("color return %i", init_color(COLOR_MAGENTA, 20, 20, 30)); // hmmm
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_MAGENTA);

	attron(COLOR_PAIR(1));
	print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ...");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	print_in_middle(stdscr, LINES / 2 + 1, 0, 0, "Viola 2!!! In color ...");
	attroff(COLOR_PAIR(2));
    	getch();
	endwin();
}
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
