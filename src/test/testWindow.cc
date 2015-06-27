#include <string>
#include "CursesWindow.h"
#include "Window.h"

using namespace nv;

int main() {
    Window w1(Rect(2, 2, 10, 10), std::string("abcde"));
    w1.refresh();
    getch();
    w1.focus();
    getch();
    w1.move(2,2);
    getch();
}
