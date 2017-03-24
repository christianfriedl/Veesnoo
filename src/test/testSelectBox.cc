#include "MenuItem.h"
#include "SelectBox.h"
#include "Screen.h"
#include "Window.h"
#include "MainLoop.h"

using namespace nv;

int main() {
    auto screen(std::make_shared<Screen>());
    auto screenRect = CursesManager::get().getMaxScreenRect();
    auto window(std::make_shared<Window>(screenRect));
    screen->addWidget(window);
    auto mainLoop(std::make_shared<MainLoop>(screen));

    auto m1 (std::make_shared<MenuItem>("option1"));
    auto m2 (std::make_shared<MenuItem>("option2"));
    auto m3 (std::make_shared<MenuItem>("option3"));

    auto sb(SelectBox::create(window, 2, 2));

    sb->addItem(m1);
    sb->addItem(m2);
    sb->addItem(m3);

    mainLoop->run();
    /*



    screen->refresh();
    getch(); // refresh, no highligts
    screen->focus();
    screen->refresh();
    getch(); // refresh, first item is focused and highlighted
    screen->receiveKey(' ');
    screen->refresh();
    getch(); // r4fresh, next item is focused and highlighted
    screen->receiveKey(' ');
    screen->refresh();
    getch(); // r4fresh, next item is focused and highlighted
    screen->receiveKey(' ');
    screen->refresh();
    getch(); // r4fresh, first item is focused and highlighted
    screen->receiveKey(' ');
    screen->refresh();
    getch(); // r4fresh, next item is focused and highlighted
    screen->receiveKey('h');
    screen->refresh();
    getch(); // r4fresh, first item is focused and highlighted
    screen->receiveKey('h');
    screen->refresh();
    getch(); // r4fresh, last item is focused and highlighted
    */
}
