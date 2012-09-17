#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvActionLabel.h"
#include"debug.h"

void testNewDeleteRefresh() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    cgString* text = cgString__new("test");
    nvWidget *l = nvActionLabel__new(10, 10, text);

    getch();
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvActionLabel_delete(l);
    printStatus("ok -- ");
}

void testSetText() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    cgString* oldText = cgString__new("old text");
    cgString* newText = cgString__new("new text");
    nvWidget *l = nvActionLabel__new(10, 10, oldText);

    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should show 'old text' now");
    getch();
    nvActionLabel_setText(l, cgString__new("new text"));
    nvWidget_refresh(l);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("label should show 'new text' now");
    getch();
    nvActionLabel_delete(l);
    printStatus("ok -- ");
}

void testFocus() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    cgString* text = cgString__new("test");
    nvWidget *l = nvActionLabel__new(10, 10, text);

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
    nvActionLabel_delete(l);
    printStatus("ok -- ");
}

static void pushMethod(nvWidget* label, void * userData) {
    mvaddstr(12, 10, "has been pushed");
    refresh();
}
void testInputChar() {
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    printStatus("%s... ", __func__);
    cgString* text = cgString__new("test");
    nvWidget *l = nvActionLabel__new(10, 10, text);
    nvActionLabel_setOnPushMethod(l, pushMethod, NULL);

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
    nvActionLabel_delete(l);
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
