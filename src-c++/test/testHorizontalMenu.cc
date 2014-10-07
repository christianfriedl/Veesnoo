#include "MenuItem.h"
#include "HorizontalMenu.h"

using namespace nv;

int main() {
    MenuItem m1("menu item 1");
    MenuItem m2("menu item 1");
    MenuItem m3("menu item 1");
    HorizontalMenu hm(2, 2);
    hm.addWidget(m1);
    hm.addWidget(m2);
    hm.addWidget(m3);

    hm.pack();
    hm.refresh();
    getch();
    hm.focus();
    getch();
    hm.receiveKey(' ');
    getch();
}
