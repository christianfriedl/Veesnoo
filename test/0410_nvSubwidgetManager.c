#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvTextbox.h"
#include"nvSubwidgetManager.h"
#include"debug.h"

void testNewDeleteRefresh() {
    printStatus("%s... ", __func__);
    nvSubwidgetManager* swm = nvSubwidgetManager__new();
    nvSubwidgetManager_delete(swm);
    printStatus("ok -- ");
}

void testRelayToOneTextbox() {
    printStatus("%s... ", __func__);
    nvWidget *tb = nvTextbox__new(10, 10, cgString__new("test"), 10);

    nvSubwidgetManager* swm = nvSubwidgetManager__new();

    nvSubwidgetManager_addWidget(swm, tb);
    nvSubwidgetManager_refresh(swm);
    printMessage("textbox 'test' should be visible now");
    getch();
    nvSubwidgetManager_delete(swm);

    printStatus("ok -- ");
}

void testRelayToTwoTextboxes() {
    printStatus("%s... ", __func__);
    nvWidget *tb = nvTextbox__new(10, 10, cgString__new("test"), 10);
    nvWidget *tb2 = nvTextbox__new(10, 11, cgString__new("test2"), 10);

    nvSubwidgetManager* swm = nvSubwidgetManager__new();

    nvSubwidgetManager_addWidget(swm, tb);
    nvSubwidgetManager_addWidget(swm, tb2);

    nvSubwidgetManager_refresh(swm);
    printMessage("textboxes 'test' and 'test2' should be visible now");
    getch();
    nvSubwidgetManager_delete(swm);

    printStatus("ok -- ");
}

void testRelayToTwoTextboxesOnTopOfEachOther() {
    printStatus("%s... ", __func__);
    nvWidget *tb = nvTextbox__new(10, 10, cgString__new("test"), 10);
    nvWidget *tb2 = nvTextbox__new(12, 10, cgString__new("test2"), 10);

    nvSubwidgetManager* swm = nvSubwidgetManager__new();

    nvSubwidgetManager_addWidget(swm, tb);
    nvSubwidgetManager_addWidget(swm, tb2);

    nvSubwidgetManager_refresh(swm);
    printMessage("textboxes 'test' and 'test2' should be visible on top of each other now");
    getch();
    nvSubwidgetManager_delete(swm);

    printStatus("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testNewDeleteRefresh();
    testRelayToOneTextbox();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    testRelayToTwoTextboxes();
    nvCursesManager_clearScreen(nvCursesManager__getInstance());
    testRelayToTwoTextboxesOnTopOfEachOther();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
