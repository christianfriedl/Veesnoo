#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/CGAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"

void testNewDelete() {
    printf("%s... ", __func__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());
    nvCursesWindow *win = nvCursesWindow__new(0, 0, 20, 20);

    getch();
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testAddBorder() {
    printf("%s... ", __func__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());
    nvCursesWindow *win = nvCursesWindow__new(0, 0, 20, 20);
    nvCursesWindow_addBorder(win);

    getch();
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testAddString() {
    printf("%s... ", __func__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());
    nvCursesWindow *win = nvCursesWindow__new(10, 10, 20, 20);
    nvCursesWindow_addString(win, "test");
    getch();
    nvCursesWindow_addString(win, " and survive");
    getch();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    CGAppState__init(__FILE__);

    testNewDelete();
    testAddBorder();
    testAddString();

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
