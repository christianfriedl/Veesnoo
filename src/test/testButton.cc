#include "CursesWindow.h"
#include "Button.h"

using namespace nv;

int main() {
    Button b1("rhabarber", 2, 2);
    b1.refresh();
    Button b2("axaluber hidraful", 20, 2);
    b2.refresh();
    Button b3("hedrupholl", 2, 3);
    b3.refresh();
    Button b4("examphhimpf", 20, 3);
    b4.refresh();
    getch();

    b1.focus();
    b1.refresh();
    getch();

    b1.receiveKey(' ');
    b1.refresh();
    getch();
}
