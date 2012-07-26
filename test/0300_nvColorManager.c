#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/CGAppState.h>
#include<cgenerics/CGString.h>
#include"nvCursesManager.h"
#include"nvColorManager.h"
#include"nvCursesWindow.h"

void testCreateColors() {
    printf("%s... ", __func__);

    int pair = nvColorManager_createColor(nvColorManager__getInstance(), COLOR_YELLOW, COLOR_BLUE);
    int pair2 = nvColorManager_createColor(nvColorManager__getInstance(), COLOR_GREEN, COLOR_YELLOW);
    int pair3 = nvColorManager_createColor(nvColorManager__getInstance(), COLOR_RED, COLOR_YELLOW);

    addstr(" normal colors");
    attron(COLOR_PAIR(pair));
    addstr(" yellow on blue");
    attroff(COLOR_PAIR(pair));
    attron(COLOR_PAIR(pair2));
    addstr(" green on yellow");
    attroff(COLOR_PAIR(pair2));
    attron(COLOR_PAIR(pair3));
    addstr(" red on yellow");
    attroff(COLOR_PAIR(pair3));
    addstr(" normal colors");

    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testNumOfColors() {
    printf("%s... ", __func__);

    int last_color = 0;
    int color = 0;
    color = nvColorManager_createColor(nvColorManager__getInstance(), COLOR_YELLOW, COLOR_BLACK);
    do {
        last_color = color;
        color = nvColorManager_createColor(nvColorManager__getInstance(), COLOR_YELLOW, COLOR_BLACK);
    } while (color > 1);
    addstr(CGString__newWithSprintf("max color: %i", last_color));
    printf("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    CGAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testCreateColors();
    testNumOfColors();

    getch();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
