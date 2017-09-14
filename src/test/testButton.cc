#include "CursesWindow.h"
#include "Button.h"

using namespace nv;

void is_pushed(const std::shared_ptr<BasicEvent>& ev) // ignore 
{
	endwin();
    std::cout << "Was pushed" << std::endl;
}
int main() {
    auto b1(std::make_shared<Button>("rhabarber", 2, 2));
    b1->onAfterPush.connect( sigc::ptr_fun(is_pushed) );
    b1->refresh();
    Button b2("axaluber hidraful", 20, 2);
    b2.refresh();
    Button b3("hedrupholl", 2, 3);
    b3.refresh();
    Button b4("examphhimpf", 20, 3);
    b4.refresh();
    getch();

    b1->focus();
    b1->refresh();
    getch();

    b1->receiveKey(' ');
    b1->refresh();
    getch();
}
