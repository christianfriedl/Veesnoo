#include "Widget.h"
#include "MenuItem.h"
#include "HorizontalMenu.h"

using namespace nv;

int main() {
    auto m1 (std::make_shared<MenuItem>("menuitem1"));
    auto m2 (std::make_shared<MenuItem>("menuitem2"));
    auto m3 (std::make_shared<MenuItem>("menuitem3"));
    auto hm = HorizontalMenu::create(6, 2);
    hm->addWidget(m1);
    hm->addWidget(m2);
    hm->addWidget(m3);

    hm->focusThis(m1);
    hm->focus();

    int ch = 0;
    do {
        hm->refresh();
        ch = getch();
        hm->receiveKey(ch);
    } while ( ch != Key_Esc );
}
