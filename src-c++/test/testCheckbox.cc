#include "CursesWindow.h"
#include "Checkbox.h"

using namespace nv;

int main() {
    Checkbox c1("rhabarber", 2, 2);
    c1.refresh();

    c1.focus();
    c1.refresh();
    getch();

    c1.receiveKey(' ');
    c1.refresh();
    getch();
}
