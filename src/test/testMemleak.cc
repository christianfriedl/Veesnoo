#include "nvwm.h"
#include <algorithm>

using namespace nv;

int main() {
    auto screen(std::make_shared<Screen>());
    auto screenRect = CursesManager::get().getMaxScreenRect();
    auto window(std::make_shared<Window>(screenRect));
    std::vector<std::shared_ptr<SelectBox>> boxes;
    for (int y = 0; y < 9; y += 2) { 
        for (int x = 0; x < 10; x += 8) {
            auto sb = SelectBox::create(window, x, y);
            boxes.emplace_back(sb);
            window->addWidget(sb);
        }
    }
    std::for_each(boxes.begin(), boxes.end(), [](auto box) { box->receiveKey(' '); box->getMenu()->close(); });
    boxes[0]->focus();
    window->refresh();
    getch();
}
