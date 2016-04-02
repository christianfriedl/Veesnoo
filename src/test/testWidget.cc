#include "CursesWindow.h"
#include "Widget.h"
#include "Logger.h"

using namespace nv;

int main() {
    Widget w(Rect(0, 0, 20, 1));
    Logger::get().log("w: ");
    Logger::get().log(w.toString());
    w.addString("1.1 string");
    w.refresh();
    getch();
    Widget w2(Rect(10, 1, 20, 1));
    Logger::get().log("w2: ");
    Logger::get().log(w2.toString());
    w2.addString("2.2 string");
    w2.refresh();
    getch();
}
