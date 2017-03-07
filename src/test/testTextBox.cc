#include <ncursesw/ncurses.h>
#include "TextBox.h"
#include "Logger.h"

using namespace nv;

void is_changed(const std::shared_ptr<ChangeEvent>& ev)
{
	endwin();
    auto tgt = std::static_pointer_cast<TextBox>(ev->getTarget());
    std::cout << "This is the changed handler, Textbox was changed to: " << tgt->getText() << std::endl;
}

void test1() {
    TextBox t1(1, 1, 10);
    t1.refresh();
    getch();
    t1.focus();
    t1.refresh();
    getch();
    t1.receiveKey('i');
    t1.receiveKey('x');
    t1.refresh();
    getch();
}

int main() {
    auto t1(std::make_shared<TextBox>(1, 1, 10));
    t1->signal_changed.connect( sigc::ptr_fun(is_changed) );
    t1->setText("abcde");
    t1->focus();
    t1->refresh();
    int ch = 0;
    while ( true ) {
        ch = getch();
        bool received = t1->receiveKey(ch);
        t1->refresh();
        if ( !received && ch == Key_Esc )
            break;
    }
    LOG("text is: '%s'", t1->getText().c_str());
}
