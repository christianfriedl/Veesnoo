#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvTextbox.h"

void testNewDeleteRefresh() {
    printf("%s... ", __func__);
    nvWidget *l = nvTextbox__new(10, 10, cgString__new("test"), 10);

    getch();
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvTextbox_delete(l);
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testSetText() {
    printf("%s... ", __func__);
    nvWidget *l = nvTextbox__new(10, 10, cgString__new("old text"), 10);

    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvTextbox_setText(l, cgString__new("new text"));
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvTextbox_delete(l);
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testInputChar() {
    printf("%s... ", __func__);
    nvWidget *l = nvTextbox__new(10, 10, cgString__new("old text"), 10);

    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvTextbox_setInputMode(l, nvInputMode_insert);
    nvTextbox_receiveKey(l, 'n');
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvTextbox_delete(l);
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

void testGeneralBehaviour() {
    printf("%s... ", __func__);
    nvWidget *tb = nvTextbox__new(10, 10, cgString__new(""), 10);

    int ch;

    do {
        nvWidget_refresh(tb);
        nvCursesManager_refresh(nvCursesManager__getInstance());
        ch = getch();
        nvTextbox_receiveKey(tb, ch);
        mvaddstr(20, 1, cgString__newFromLengthAndPreset(100, ' ')); /* leaks memory! */
        mvaddstr(20, 1, cgString__newWithSprintf("current text: '%s'", nvTextbox_getText(tb))); /* leaks memory! */
    } while (1);                /* can out-C-C anyway */

    cgString *s = nvTextbox_getText(tb);

    mvwaddstr(stdscr, 20, 1, s);
    nvTextbox_delete(tb);
    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    /*
    testNewDeleteRefresh();
    testSetText();
    testInputChar();
    */
    testGeneralBehaviour();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
