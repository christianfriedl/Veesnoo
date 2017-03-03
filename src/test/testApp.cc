#include "Screen.h"
#include "TextBox.h"
#include "MainLoop.h"

using namespace nv;

int main() {
    auto screen(std::make_shared<Screen>());
    auto mainLoop(std::make_shared<MainLoop>(screen));
    auto tb1(std::make_shared<TextBox>(0, 0, 20));
    screen->addWidget(tb1);
    mainLoop->run();
}
