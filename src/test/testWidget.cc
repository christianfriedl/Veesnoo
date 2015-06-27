#include "CursesWindow.h"
#include "Widget.h"

using namespace nv;

int main() {
    Widget win(Rect(1, 1, 100, 30));
    Widget w(Rect(0, 0, 20, 1));
    w.addString("1.1 string");
    w.refresh();
    Widget w2(Rect(1, 1, 20, 1));
    w2.addString("2.2 string");
    w2.refresh();
    getch();
}
