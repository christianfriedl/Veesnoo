#include "TextBox.h"

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
    int ch = 0;
    while ( true ) {
        ch = getch();
        bool received = t1.receiveKey(ch);
        t1.refresh();
        if ( !received && ch == Key_Esc )
            break;
    }
}
