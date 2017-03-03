#include <string>
#include "MainWindow.h"

using namespace nv;

int main() {
    MainWindow w1(Rect(2, 2, 10, 10), std::string("abcde"));
    w1.refresh();
    getch();
    w1.focus();
    getch();
}
