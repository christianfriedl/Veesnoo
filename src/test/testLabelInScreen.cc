#include "nvwm.h"

using namespace nv;

int main() {
    auto screen(std::make_shared<Screen>());
    auto screenRect = CursesManager::get().getMaxScreenRect();
    auto window(std::make_shared<Window>(screenRect));
    screen->addWidget(window);
    auto mainLoop(std::make_shared<MainLoop>(screen));

    auto label(std::make_shared<Label>("abcde", 1, 1));
    window->addWidget(label);
    mainLoop->run();
}
