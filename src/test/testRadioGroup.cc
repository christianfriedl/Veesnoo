#include "CursesWindow.h"
#include "RadioButton.h"
#include "RadioGroup.h"

using namespace nv;

int main() {
    auto c1(std::make_shared<RadioButton>(2, 2, "1"));
    auto c2(std::make_shared<RadioButton>(5, 2, "2"));
    auto c3(std::make_shared<RadioButton>(8, 2, "3"));

    RadioGroup rg;
    rg.addButton(c1);
    rg.addButton(c2);
    rg.addButton(c3);

    c1->refresh();
    c2->refresh();
    c3->refresh();
    getch();

    c1->focus();
    c1->receiveKey(' ');
    c1->refresh();
    c2->refresh();
    c3->refresh();
    getch();

    c2->receiveKey(' ');
    c1->refresh();
    c2->refresh();
    c3->refresh();
    getch();
    getch();
}
