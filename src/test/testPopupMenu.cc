#include <ncursesw/ncurses.h>
#include "MenuItem.h"
#include "PopupMenu.h"
#include "MainLoop.h"

using namespace nv;

int main() {
    auto m1 (std::make_shared<MenuItem>("menuitem1"));
    auto m2 (std::make_shared<MenuItem>("menuitem2"));
    auto m3 (std::make_shared<MenuItem>("menuitem3"));
    auto m (PopupMenu::create(0, 0));

    m->addItem(m1);
    m->addItem(m2);
    m->addItem(m3);

    MainLoop ml(m);

    ml.run();
}
