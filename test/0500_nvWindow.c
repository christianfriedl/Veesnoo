#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvTextbox.h"
#include"nvLabel.h"
#include"nvWindow.h"
#include"debug.h"

void testNewDeleteRefresh() {
    printStatus("%s... ", __func__);
    nvWidget* w = nvWindow__new(0, 0, 20, 20);
    nvWidget_refresh(w);
    nvWindow_delete(w);
    printStatus("ok -- ");
}

void testRelayToOneTextbox() {
    printStatus("%s... ", __func__);
    nvWidget *tb = nvTextbox__new(0, 0, cgString__new("test"), 10);

    nvWidget* w = nvWindow__new(0, 1, 12, 3);

    nvWindow_addWidget(w, tb);
    nvWindow_refresh(w);
    printMessage("textbox 'test' should be visible inside a tiny window now");
    getch();
    nvWindow_receiveKey(w, 'i');
    nvWindow_receiveKey(w, 'a');
    nvWindow_refresh(w);
    printMessage("textbox 'test' should have an 'a' now");
    getch();
    nvWindow_delete(w);

    printStatus("ok -- ");
}

void testRefrehTwoLabels() {
    printStatus("%s... ", __func__);

    nvWidget *l1 = nvLabel__new(0, 0, cgString__new("test1"));
    nvWidget *l2 = nvLabel__new(0, 1, cgString__new("test2"));

    nvWidget* w = nvWindow__new(0, 1, 12, 4);

    nvWindow_addWidget(w, l1);
    nvWindow_addWidget(w, l2);

    nvWindow_refresh(w);
    printMessage("2 textboxes should be visible inside a tiny window now");
    getch();
    nvLabel_delete(l1);
    nvLabel_delete(l2);
    nvWindow_delete(w);

    printStatus("ok -- ");
}

void testImplicitResize() {
    printStatus("%s... ", __func__);

    nvWidget *l1 = nvLabel__new(0, 0, cgString__new("test1 is much too long"));

    nvWidget* w = nvWindow__new(0, 1, 12, 3);

    nvWindow_addWidget(w, l1);

    nvWindow_refresh(w);
    printMessage("label should be cut to window size");
    getch();
    nvLabel_delete(l1);
    nvWindow_delete(w);

    printStatus("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testNewDeleteRefresh();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    testRelayToOneTextbox();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    testRefrehTwoLabels();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    testImplicitResize();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
