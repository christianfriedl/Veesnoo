/*
 * have only one container, so we can easily debug memory management
 */

#include <memory>
#include "Widget.h"
#include "Container.h"
#include "Logger.h"

using namespace nv;

int main() {
     Container c(Rect(0, 0, 20, 1));
     auto w(std::make_shared<Widget>(Rect(0, 0, 1, 1)));
     c.addWidget(w);
    // we don't even wait for getch()
}
