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
    Widget w3(Rect(1, 1, 20, 20));
    Logger::get().log("w3: ");
    Logger::get().log(w3.toString());
    w3.refresh();
    getch();
    Widget w4(Rect(1, 1, 10, 1));
    w4.setParent(w3);
    Logger::get().log("w3 -> w4: ");
    Logger::get().log(w4.toString());
    w3.refresh();
    getch();
}
