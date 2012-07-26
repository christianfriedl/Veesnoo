#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/CGAppState.h>
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

int main() {
    printf("=== %s ===\n", __FILE__);
    CGAppState__init(__FILE__);

    testInit();
    testCreateDestroyWindow();

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
