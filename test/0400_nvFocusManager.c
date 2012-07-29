#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvTextbox.h"
#include"nvFocusManager.h"
#include"debug.h"

void testNewDeleteRefresh() {
    printStatus("%s... ", __func__);
    nvFocusManager* fm = nvFocusManager__new();
    nvFocusManager_delete(fm);
    printStatus("ok -- ");
}

void testRelayToOneTextbox() {
    printStatus("%s... ", __func__);
    nvWidget *tb = nvTextbox__new(10, 10, cgString__new("test"), 10);

    nvFocusManager* fm = nvFocusManager__new();

    nvFocusManager_addWidget(fm, tb);
    bool rv = nvFocusManager_receiveKey(fm, 'i');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, 'a');
    rv = nvFocusManager_receiveKey(fm, 'b');
    rv = nvFocusManager_receiveKey(fm, 'c');
    assert(rv == true);
    assert(cgString__compare(nvTextbox_getText(tb), "abctest") == 0);

    nvFocusManager_delete(fm);

    printStatus("ok -- ");
}

void testRelayToTwoTextboxes() {
    printStatus("%s... ", __func__);
    nvWidget *tb = nvTextbox__new(10, 10, cgString__new("test"), 10);
    nvWidget *tb2 = nvTextbox__new(10, 11, cgString__new("test"), 10);

    nvFocusManager* fm = nvFocusManager__new();

    nvFocusManager_addWidget(fm, tb);
    nvFocusManager_addWidget(fm, tb2);
    bool rv = nvFocusManager_receiveKey(fm, 'i');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, 'a');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, 'b');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, 'c');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, NV_ENTER);
    assert(rv == true);
    assert(cgString__compare(nvTextbox_getText(tb), "abctest") == 0);

    rv = nvFocusManager_receiveKey(fm, NV_TAB);
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, 'i');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, 'a');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, 'b');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, 'c');
    assert(rv == true);
    rv = nvFocusManager_receiveKey(fm, NV_ENTER);
    assert(rv == true);
    assert(cgString__compare(nvTextbox_getText(tb2), "abctest") == 0);

    nvFocusManager_delete(fm);

    printStatus("ok -- ");
}

void testGeneralBehaviour() {
    printf("%s... ", __func__);
    nvWidget *tb = nvTextbox__new(10, 10, cgString__new(""), 10);
    nvWidget *tb2 = nvTextbox__new(10, 11, cgString__new(""), 10);

    nvFocusManager* fm = nvFocusManager__new();

    nvFocusManager_addWidget(fm, tb);
    nvFocusManager_addWidget(fm, tb2);

    int ch;

    do {
        nvWidget_refresh(tb);
        nvWidget_refresh(tb2);
        nvCursesManager_refresh(nvCursesManager__getInstance());
        ch = getch();
        nvFocusManager_receiveKey(fm, ch);
        printMessage("exit with F1 -- texts are: tb '%s', tb2 '%s'", nvTextbox_getText(tb), nvTextbox_getText(tb2));
    } while (ch != KEY_F(1));                /* can out-C-C anyway */

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());
    printf("ok -- ");
}

int main() {
    printf("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testNewDeleteRefresh();
    testRelayToOneTextbox();
    //testRelayToTwoTextboxes();
    testGeneralBehaviour();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printf("=== %s ok ===\n", __FILE__);
    return 0;
}
