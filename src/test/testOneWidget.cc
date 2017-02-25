/*
 * have only one widget, so we can easily debug memory management
 */

#include <memory>
#include "CursesWindow.h"
#include "Widget.h"
#include "Logger.h"

using namespace nv;

int main() {
    Widget w(Rect(0, 0, 20, 1));
    // we don't even wait for getch()
}
