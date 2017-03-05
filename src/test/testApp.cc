#include "nvwm.h"

using namespace nv;

int main() {
    auto screen(std::make_shared<Screen>());
    auto screenRect = CursesManager::get().getMaxScreenRect();
    auto window(std::make_shared<Window>(screenRect));
    screen->addWidget(window);
    auto mainLoop(std::make_shared<MainLoop>(screen));
    auto ltb1(std::make_shared<Label>("Text here:", 0, 0));
    window->addWidget(ltb1);
    auto tb1(std::make_shared<TextBox>(20, 0, 20));
    window->addWidget(tb1);
    auto lcb1(std::make_shared<Label>("Check here:", 0, 2));
    window->addWidget(lcb1);
    auto cb1(std::make_shared<Checkbox>(20, 2));
    window->addWidget(cb1);
    auto cb2(std::make_shared<Checkbox>(24, 2));
    cb2->setFrame("()");
    window->addWidget(cb2);
    mainLoop->run();
}
