#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<cgenerics/cgAppState.h>
#include"nvCursesManager.h"
#include"nvCursesWindow.h"
#include"nvCheckbox.h"
#include"debug.h"

void testNewDeleteRefresh() {
    printStatus("%s... ", __func__);
    nvWidget *cb = nvCheckbox__new(10, 10, true);

    getch();
    nvWidget_refresh(cb);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    getch();
    nvCheckbox_delete(cb);
    printStatus("ok -- ");
}

void testSetValue() {
    printStatus("%s... ", __func__);
    nvWidget *cb = nvCheckbox__new(10, 10, false);

    nvWidget_refresh(cb);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("checkbox should be unset - %i", nvCheckbox_getValue(cb));
    getch();
    nvCheckbox_setValue(cb, true);
    nvWidget_refresh(cb);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("checkbox should be set - %i", nvCheckbox_getValue(cb));
    getch();
    nvCheckbox_delete(cb);
    printStatus("ok -- ");
}

void testInputChar() {
    printStatus("%s... ", __func__);
    nvWidget *cb = nvCheckbox__new(10, 10, false);

    nvWidget_refresh(cb);
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("checkbox should be unset");
    getch();
    nvCheckbox_setInputMode(cb, nvInputMode_insert);
    nvCheckbox_receiveKey(cb, ' ');
    nvCursesManager_refresh(nvCursesManager__getInstance());
    printMessage("checkbox should be set");
    getch();
    nvCheckbox_delete(cb);
    printStatus("ok -- ");
}

void testGeneralBehaviour() {
    printStatus("%s... ", __func__);
    nvWidget *cb = nvCheckbox__new(10, 10, false);

    int ch;

    do {
        nvWidget_refresh(cb);
        nvCursesManager_refresh(nvCursesManager__getInstance());
        ch = getch();
        nvCheckbox_receiveKey(cb, ch);
        if (nvCheckbox_getValue(cb) == true)
            printMessage("checkbox is now set");
        else
            printMessage("checkbox is now unset");
    } while (1);                /* can out-C-C anyway */

    nvCheckbox_delete(cb);
    printStatus("ok -- ");
}

int main() {
    printStatus("=== %s ===\n", __FILE__);
    cgAppState__init(__FILE__);
    nvCursesManager_initCurses(nvCursesManager__getInstance());

    testNewDeleteRefresh();
    testSetValue();
    testInputChar();
    testGeneralBehaviour();

    nvCursesManager_uninitCurses(nvCursesManager__getInstance());
    nvCursesManager_delete(nvCursesManager__getInstance());

    printStatus("=== %s ok ===\n", __FILE__);
    return 0;
}
