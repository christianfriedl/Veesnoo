#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"

void testInit() {
    printf("%s... ", __func__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());
    getch();
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testCreateDestroyWindow() {
    printf("%s... ", __func__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());
    WINDOW* win = nvCursesManager_createWindow(nvCursesManager__getInstance(), 0, 0, 20, 20);
    getch();
    nvCursesManager_destroyWindow(nvCursesManager__getInstance(), win);
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testClearScreen() {
    printf("%s... ", __func__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());
    addstr("visible now... push button to vanish");
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);

    testInit();
    testCreateDestroyWindow();
    testClearScreen();

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
