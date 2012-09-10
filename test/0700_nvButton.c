#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvButton.h"
#include"debug.h"

void testNewDeleteRefresh() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    cgString* text = cgString__new("test");
    nvWidget *l = nvButton__new(10, 10, text);

    getch();
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvButton_delete(l);
    printStatus("ok -- ");
}

void testSetText() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    cgString* oldText = cgString__new("old text");
    cgString* newText = cgString__new("new text");
    nvWidget *l = nvButton__new(10, 10, oldText);

    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should show 'old text' now");
    getch();
    nvButton_setText(l, cgString__new("new text"));
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should show 'new text' now");
    getch();
    nvButton_delete(l);
    printStatus("ok -- ");
}

void testFocus() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    cgString* text = cgString__new("test");
    nvWidget *l = nvButton__new(10, 10, text);

    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should not be highlighted");
    getch();
    nvWidget_focus(l);
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should be highlighted");
    getch();
    nvWidget_deFocus(l);
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should not be highlighted");
    getch();
    nvButton_delete(l);
    printStatus("ok -- ");
}

static void pushMethod(nvWidget* label) {
    mvaddstr(12, 10, "has been pushed");
    refresh();
}
void testInputChar() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    cgString* text = cgString__new("test");
    nvWidget *l = nvButton__new(10, 10, text);
    nvButton_setOnPushMethod(l, pushMethod);

    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvWidget_receiveKey(l, NV_ENTER);
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should not be highlighted; you should see no 'has been pushed' text");
    getch();
    nvWidget_focus(l);
    nvWidget_receiveKey(l, NV_ENTER);
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should be highlighted; you should see a 'has been pushed' text");
    getch();
    nvButton_delete(l);
    printStatus("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testNewDeleteRefresh();
    testSetText();
    testFocus();
    testInputChar();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
