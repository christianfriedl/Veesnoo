#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvTextbox.h"
#include"nvHorizontalMenu.h"
#include"nvActionLabel.h"
#include"debug.h"

void testNewDeleteRefresh() {
    printStatus("%s... ", __func__);
    nvWidget *w = nvHorizontalMenu__new(0, 0);

    nvWidget_refresh(w);
    nvHorizontalMenu_delete(w);
    printStatus("ok -- ");
}

void i1Pushed(nvWidget* widget, void * userData) {
    mvaddstr(11, 0, "item1 pushed!");
    refresh();
}
void i2Pushed(nvWidget* widget, void * userData) {
    mvaddstr(11, 0, "item2 pushed!");
    refresh();
}
void i3Pushed(nvWidget* widget, void * userData) {
    mvaddstr(11, 0, "item3 pushed!");
    refresh();
}
void testThreeItems() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    mvaddstr( 10, 0,"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    nvWidget *w = nvHorizontalMenu__new(0, 10);
    nvWidget *i1 = nvActionLabel__new(0, 0, cgString__new("item1"));
    nvActionLabel_setOnPushMethod(i1, i1Pushed, NULL);
    nvWidget *i2 = nvActionLabel__new(0, 0, cgString__new("item2"));
    nvActionLabel_setOnPushMethod(i2, i2Pushed, NULL);
    nvWidget *i3 = nvActionLabel__new(0, 0, cgString__new("item3"));
    nvActionLabel_setOnPushMethod(i3, i3Pushed, NULL);


    nvHorizontalMenu_addWidget(w, i1);
    nvHorizontalMenu_addWidget(w, i2);
    nvHorizontalMenu_addWidget(w, i3);
    nvHorizontalMenu_refresh(w);
    printMessage("no item should be highlighted");
    getch();
    nvHorizontalMenu_focus(w);
    nvHorizontalMenu_refresh(w);
    nvHorizontalMenu_receiveKey(w, NV_ENTER);
    printMessage("1st item should be highlighted");
    getch();
    nvHorizontalMenu_receiveKey(w, NV_TAB);
    nvHorizontalMenu_refresh(w);
    nvHorizontalMenu_receiveKey(w, NV_ENTER);
    printMessage("2nd item should be highlighted");
    getch();
    nvHorizontalMenu_receiveKey(w, NV_TAB);
    nvHorizontalMenu_refresh(w);
    nvHorizontalMenu_receiveKey(w, NV_ENTER);
    printMessage("3rd item should be highlighted");
    getch();
    nvHorizontalMenu_receiveKey(w, NV_TAB);
    nvHorizontalMenu_refresh(w);
    nvHorizontalMenu_receiveKey(w, NV_ENTER);
    printMessage("1st item should be highlighted");
    getch();
    nvHorizontalMenu_deFocus(w);
    nvHorizontalMenu_refresh(w);
    printMessage("no item should be highlighted");
    getch();

    nvHorizontalMenu_delete(w);

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
