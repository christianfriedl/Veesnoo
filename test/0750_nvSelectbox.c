#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvTextbox.h"
#include"nvSelectbox.h"
#include"nvActionLabel.h"
#include"debug.h"

void testNewDeleteRefresh() {
    printStatus("%s... ", __func__);
    nvWidget *w = nvSelectbox__new(0, 0);

    nvWidget_refresh(w);
    nvSelectbox_delete(w);
    printStatus("ok -- ");
}

void testThreeItems() {
    printStatus("%s... ", __func__);
    nvWidget *s = nvSelectbox__new(10, 10);

    nvSelectbox_addItem(s, "item1");
    nvSelectbox_addItem(s, "item2");
    nvSelectbox_addItem(s, "item3");

    nvSelectbox_refresh(s);
    printMessage("nothing should be visible");
    getch();
    nvWidget_focus(s);
    nvSelectbox_refresh(s);
    printMessage("menu should be visible");
    getch();
    nvSelectbox_receiveKey(s, KEY_DOWN);
    nvSelectbox_refresh(s);
    printMessage("1st item should be highlighted");
    getch();
    nvSelectbox_receiveKey(s, NV_TAB);
    nvSelectbox_refresh(s);
    nvSelectbox_receiveKey(s, NV_ENTER);
    printMessage("2nd item should be highlighted");
    getch();
    nvSelectbox_receiveKey(s, NV_TAB);
    nvSelectbox_refresh(s);
    nvSelectbox_receiveKey(s, NV_ENTER);
    printMessage("3rd item should be highlighted");
    getch();
    nvSelectbox_receiveKey(s, NV_TAB);
    nvSelectbox_refresh(s);
    nvSelectbox_receiveKey(s, NV_ENTER);
    printMessage("1st item should be highlighted");
    getch();
    nvWidget_deFocus(s);
    nvSelectbox_refresh(s);
    printMessage("popup menu should be invisible");
    getch();

    nvSelectbox_delete(s);

    printStatus("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testNewDeleteRefresh();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    testThreeItems();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
