#include "MenuItem.h"
#include "PopupMenu.h"

using namespace nv;

int main() {
    MenuItem m1("menu item 1");
    MenuItem m2("menu item 2");
    MenuItem m3("menu item 3");
    PopupMenu pm(2, 2);
    pm.addItem(m1);
    pm.addItem(m2);
    pm.addItem(m3);

    pm.pack();
    pm.refresh();
    getch(); // refresh, no highligts
    pm.focus();
    pm.refresh();
    getch(); // refresh, first item is focused and highlighted
    pm.receiveKey(' ');
    pm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    pm.receiveKey(' ');
    pm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    pm.receiveKey(' ');
    pm.refresh();
    getch(); // r4fresh, first item is focused and highlighted
    pm.receiveKey(' ');
    pm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    pm.receiveKey('h');
    pm.refresh();
    getch(); // r4fresh, first item is focused and highlighted
    pm.receiveKey('h');
    pm.refresh();
    getch(); // r4fresh, last item is focused and highlighted

    pm.focusThis(1);
    pm.refresh();
    getch(); // r4fresh, 2nd item is focused and highlighted
}
