#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvTextbox.h"
#include"nvPopupMenu.h"
#include"nvActionLabel.h"
#include"debug.h"

void testNewDeleteRefresh() {
    printStatus("%s... ", __func__);
    nvWidget *w = nvPopupMenu__new(0, 0);

    nvWidget_refresh(w);
    nvPopupMenu_delete(w);
    printStatus("ok -- ");
}

void i1Pushed(nvWidget* widget) {
    mvaddstr(15, 0, "item1 pushed!");
    refresh();
}
void i2Pushed(nvWidget* widget) {
    mvaddstr(15, 0, "item2 pushed!");
    refresh();
}
void i3Pushed(nvWidget* widget) {
    mvaddstr(15, 0, "item3 pushed!");
    refresh();
}
void testThreeItems() {
    printStatus("%s... ", __func__);
    nvWidget *w = nvPopupMenu__new(0, 10);
    nvWidget *i1 = nvActionLabel__new(0, 0, cgString__new("item1"));
    nvActionLabel_setOnPushMethod(i1, i1Pushed);
    nvWidget *i2 = nvActionLabel__new(0, 0, cgString__new("item2"));
    nvActionLabel_setOnPushMethod(i2, i2Pushed);
    nvWidget *i3 = nvActionLabel__new(0, 0, cgString__new("item3"));
    nvActionLabel_setOnPushMethod(i3, i3Pushed);


    nvPopupMenu_addWidget(w, i1);
    nvPopupMenu_addWidget(w, i2);
    nvPopupMenu_addWidget(w, i3);
    nvPopupMenu_refresh(w);
    printMessage("no item should be highlighted");
    getch();
    nvWidget_focus(w);
    nvPopupMenu_refresh(w);
    nvPopupMenu_receiveKey(w, NV_ENTER);
    printMessage("1st item should be highlighted");
    getch();
    nvPopupMenu_receiveKey(w, NV_TAB);
    nvPopupMenu_refresh(w);
    nvPopupMenu_receiveKey(w, NV_ENTER);
    printMessage("2nd item should be highlighted");
    getch();
    nvPopupMenu_receiveKey(w, NV_TAB);
    nvPopupMenu_refresh(w);
    nvPopupMenu_receiveKey(w, NV_ENTER);
    printMessage("3rd item should be highlighted");
    getch();
    nvPopupMenu_receiveKey(w, NV_TAB);
    nvPopupMenu_refresh(w);
    nvPopupMenu_receiveKey(w, NV_ENTER);
    printMessage("1st item should be highlighted");
    getch();
    nvWidget_deFocus(w);
    nvPopupMenu_refresh(w);
    printMessage("no item should be highlighted");
    getch();

    nvPopupMenu_delete(w);

    nvActionLabel_delete(i1);
    nvActionLabel_delete(i2);
    nvActionLabel_delete(i3);

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
