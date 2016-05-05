#include <memory>
#include "CursesWindow.h"
#include "Widget.h"
#include "Logger.h"

using namespace nv;

int main() {
    Widget w(Rect(0, 0, 20, 1));
    Logger::get().log("w: ");
    Logger::get().log(w.toString());
    Logger::get().log("should be at 0, 0, size 20, 1");
    w.addString("1.1 string");
    w.refresh();
    getch();
    Widget w2(Rect(10, 1, 20, 1));
    Logger::get().log("w2: ");
    Logger::get().log(w2.toString());
    Logger::get().log("should be at 10, 2 size 20, 1");
    w2.addString("2.2 string");
    w2.refresh();
    getch();
    auto w3 = std::make_shared<Widget>(Rect(1, 1, 20, 20));
    Logger::get().log("w3: ");
    Logger::get().log(w3->toString());
    Logger::get().log("should be at 1, 1 size 20, 20");
    w3->refresh();
    getch();
    Widget w4(Rect(1, 1, 10, 1));
    w4.setParent(w3.get());
    Logger::get().log("w4 ( in w3) : ");
    Logger::get().log(w4.toString());
    Logger::get().log("should be at 2, 2, size 10, 1");
    w3->refresh();
    getch();
}
