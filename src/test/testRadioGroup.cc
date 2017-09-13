#include<algorithm>
#include "nvwm.h"

using namespace nv;

void testVeryMany() {
    auto screen(std::make_shared<Screen>());
    auto screenRect = CursesManager::get().getMaxScreenRect();
    auto window(std::make_shared<Window>(screenRect));
    screen->addWidget(window);
    auto mainLoop(std::make_shared<MainLoop>(screen));

    auto group(std::make_shared<RadioGroup>());
    std::vector<std::shared_ptr<RadioButton>> buttons;

    // 9600 buttons
    for (int y = 0; y < 90; y += 2) { 
        for (int x = 0; x < 160; x += 5)
            buttons.emplace_back(std::make_shared<RadioButton>(x, y, "")); 
    }
    std::for_each(buttons.begin(), buttons.end(), [&window, &group](std::shared_ptr<RadioButton> rb) { window->addWidget(rb); group->addButton(rb); });

    mainLoop->run();
}

void testAFew() {
    auto c1(std::make_shared<RadioButton>(2, 2, "1"));
    auto c2(std::make_shared<RadioButton>(5, 2, "2"));
    auto c3(std::make_shared<RadioButton>(8, 2, "3"));

    RadioGroup rg;
    rg.addButton(c1);
    rg.addButton(c2);
    rg.addButton(c3);

    c1->refresh();
    c2->refresh();
    c3->refresh();
    getch();

    c1->focus();
    c1->receiveKey(' ');
    c1->refresh();
    c2->refresh();
    c3->refresh();
    getch();

    c2->receiveKey(' ');
    c1->refresh();
    c2->refresh();
    c3->refresh();
    getch();
    getch();
}

int main() {
    testVeryMany();
}
