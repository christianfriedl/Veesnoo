#include <memory>
#include "Widget.h"
#include "MenuItem.h"
#include "HorizontalMenu.h"

using namespace nv;

int main() {
    auto m1 (std::make_shared<MenuItem>("menu item 1"));
    auto m2 (std::make_shared<MenuItem>("menu item 2"));
    auto m3 (std::make_shared<MenuItem>("menu item 3"));
    HorizontalMenu hm(6, 2);
    hm.addWidget(m1);
    hm.addWidget(m2);
    hm.addWidget(m3);

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

    hm.focusThis(m2);
    hm.refresh();
    getch(); // r4fresh, 2nd item is focused and highlighted
}
