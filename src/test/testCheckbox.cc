#include "CursesWindow.h"
#include "Checkbox.h"

using namespace nv;

int main() {
    Checkbox c1(2, 2);
    c1.refresh();
    move(10, 10);
    getch();

    c1.focus();
    c1.refresh();
    move(10, 10);
    getch();

    c1.receiveKey(' ');
    c1.refresh();
    move(10, 10);
    getch();

    Checkbox c2(2, 3);
    c2.setFrame("()");
    c2.refresh();
    move(10, 10);
    getch();

    c2.focus();
    c2.refresh();
    move(10, 10);
    getch();

    c2.receiveKey(' ');
    c2.refresh();
    move(10, 10);
    getch();
}
