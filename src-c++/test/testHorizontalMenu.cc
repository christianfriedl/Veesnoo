#include "MenuItem.h"
#include "HorizontalMenu.h"

using namespace nv;

int main() {
    MenuItem m1("menu item 1");
    MenuItem m2("menu item 2");
    MenuItem m3("menu item 3");
    HorizontalMenu hm(2, 2);
    hm.addWidget(m1);
    hm.addWidget(m2);
    hm.addWidget(m3);

    hm.pack();
    hm.refresh();
    getch(); // refresh, no highligts
    hm.focus();
    hm.refresh();
    getch(); // refresh, first item is focused and highlighted
    hm.receiveKey(' ');
    hm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    hm.receiveKey(' ');
    hm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    hm.receiveKey(' ');
    hm.refresh();
    getch(); // r4fresh, first item is focused and highlighted
    hm.receiveKey(' ');
    hm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    hm.receiveKey('h');
    hm.refresh();
    getch(); // r4fresh, first item is focused and highlighted
    hm.receiveKey('h');
    hm.refresh();
    getch(); // r4fresh, last item is focused and highlighted

    hm.focusThis(1);
    hm.refresh();
    getch(); // r4fresh, 2nd item is focused and highlighted
}
