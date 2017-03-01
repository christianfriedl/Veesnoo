#include <ncursesw/ncurses.h>
#include "MenuItem.h"
#include "PopupMenu.h"

using namespace nv;

int main() {
    auto m1 (std::make_shared<MenuItem>("menuitem1"));
    auto m2 (std::make_shared<MenuItem>("menuitem2"));
    auto m3 (std::make_shared<MenuItem>("menuitem3"));
    auto m (std::make_shared<PopupMenu>(0, 0));

    m->addItem(m1);
    m->addItem(m2);
    m->addItem(m3);

    m->focus();

    int ch = 0;
    do {
        m->refresh();
        refresh();
        ch = CursesManager::getInstance().getCh();
        m->receiveKey(ch);
    } while ( ch != Key_Esc );
}
