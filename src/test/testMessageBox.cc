#include "Window.h"
#include "MessageBox.h"

using namespace nv;

int main() {
    auto w1 = Window::create(Rect(10, 10, 100, 20), "fenst");
    auto mb1 = MessageBox::create("rhabarber", "rhubarbh");
    w1->addWidget(mb1);
    mb1->layout();
    w1->refresh();
    getch();
}
