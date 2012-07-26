#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"

void testNewDelete() {
    printf("%s... ", __func__);
    nvCursesWindow *win = nvCursesWindow__new(0, 0, 20, 20);

    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testAddBorder() {
    printf("%s... ", __func__);
    nvCursesWindow *win = nvCursesWindow__new(0, 0, 20, 20);
    nvCursesWindow_addBorder(win);

    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testAddString() {
    printf("%s... ", __func__);
    nvCursesWindow *win = nvCursesWindow__new(10, 10, 20, 20);
    nvCursesWindow_addString(win, "test");
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvCursesWindow_addString(win, " and survive");
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();

    printf("ok -- ");
}

void testAddStringAt() {
    printf("%s... ", __func__);
    nvCursesWindow *win = nvCursesWindow__new(10, 10, 20, 20);
    nvCursesWindow_addStringAt(win, 1, 1, "test");
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvCursesWindow_addStringAt(win, 1, 2, "and survive");
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();

    printf("ok -- ");
}

void testAttrOnOff() {
    printf("%s... ", __func__);

    nvCursesWindow *win = nvCursesWindow__new(10, 10, 20, 20);
    nvCursesWindow_attrOn(win, A_REVERSE);
    nvCursesWindow_addString(win, "test");
    nvCursesWindow_attrOff(win, A_REVERSE);

    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();

    nvCursesWindow_addString(win, " and survive");

    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();

    printf("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testNewDelete();
    testAddBorder();
    testAddString();
    testAddStringAt();
    testAttrOnOff();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
