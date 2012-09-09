#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvTextbox.h"
#include"nvVerticalMenu.h"
#include"nvActionLabel.h"
#include"debug.h"

void testNewDeleteRefresh() {
    printStatus("%s... ", __func__);
    nvWidget *w = nvVerticalMenu__new(0, 0);

    nvWidget_refresh(w);
    nvVerticalMenu_delete(w);
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
    nvWidget *w = nvVerticalMenu__new(0, 10);
    nvWidget *i1 = nvActionLabel__new(0, 0, cgString__new("item1"));
    nvActionLabel_setOnPushMethod(i1, i1Pushed);
    nvWidget *i2 = nvActionLabel__new(0, 0, cgString__new("item2"));
    nvActionLabel_setOnPushMethod(i2, i2Pushed);
    nvWidget *i3 = nvActionLabel__new(0, 0, cgString__new("item3"));
    nvActionLabel_setOnPushMethod(i3, i3Pushed);


    nvVerticalMenu_addWidget(w, i1);
    nvVerticalMenu_addWidget(w, i2);
    nvVerticalMenu_addWidget(w, i3);
    nvVerticalMenu_refresh(w);
    printMessage("no item should be highlighted");
    getch();
    nvVerticalMenu_focus(w);
    nvVerticalMenu_refresh(w);
    nvVerticalMenu_receiveKey(w, NV_ENTER);
    printMessage("1st item should be highlighted");
    getch();
    nvVerticalMenu_receiveKey(w, NV_TAB);
    nvVerticalMenu_refresh(w);
    nvVerticalMenu_receiveKey(w, NV_ENTER);
    printMessage("2nd item should be highlighted");
    getch();
    nvVerticalMenu_receiveKey(w, NV_TAB);
    nvVerticalMenu_refresh(w);
    nvVerticalMenu_receiveKey(w, NV_ENTER);
    printMessage("3rd item should be highlighted");
    getch();
    nvVerticalMenu_receiveKey(w, NV_TAB);
    nvVerticalMenu_refresh(w);
    nvVerticalMenu_receiveKey(w, NV_ENTER);
    printMessage("1st item should be highlighted");
    getch();
    nvVerticalMenu_deFocus(w);
    nvVerticalMenu_refresh(w);
    printMessage("no item should be highlighted");
    getch();

    nvVerticalMenu_delete(w);

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
