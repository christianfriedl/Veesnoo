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
    nvWidget* l = nvTextbox__new(10, 10, cgString__new("test"));
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
    nvWidget* l = nvTextbox__new(10, 10, cgString__new("old text"));
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
    nvWidget* l = nvTextbox__new(10, 10, cgString__new("old text"));
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

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testNewDeleteRefresh();
    testSetText();
    testInputChar();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
