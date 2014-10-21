#include "MenuItem.h"
#include "VerticalMenu.h"

using namespace nv;

int main() {
    MenuItem m1("menu item 1");
    MenuItem m2("menu item 2");
    MenuItem m3("menu item 3");
    VerticalMenu vm(2, 2);
    vm.addWidget(m1);
    vm.addWidget(m2);
    vm.addWidget(m3);

    vm.pack();
    vm.refresh();
    getch(); // refresh, no highligts
    vm.focus();
    vm.refresh();
    getch(); // refresh, first item is focused and highlighted
    vm.receiveKey(' ');
    vm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    vm.receiveKey(' ');
    vm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    vm.receiveKey(' ');
    vm.refresh();
    getch(); // r4fresh, first item is focused and highlighted
    vm.receiveKey(' ');
    vm.refresh();
    getch(); // r4fresh, next item is focused and highlighted
    vm.receiveKey('h');
    vm.refresh();
    getch(); // r4fresh, first item is focused and highlighted
    vm.receiveKey('h');
    vm.refresh();
    getch(); // r4fresh, last item is focused and highlighted

    vm.focusThis(1);
    vm.refresh();
    getch(); // r4fresh, 2nd item is focused and highlighted
}
