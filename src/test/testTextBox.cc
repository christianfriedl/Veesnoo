#include "TextBox.h"
#include "Logger.h"

using namespace nv;

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
    TextBox t1(1, 1, 10);
    t1.setText("abcde");
    t1.focus();
    t1.refresh();
    int ch = 0;
    while ( true ) {
        ch = getch();
        bool received = t1.receiveKey(ch);
        t1.refresh();
        if ( !received && ch == Key_Esc )
            break;
    }
    LOG("text is: '%s'", t1.getText().c_str());
}
