#include "Label.h"

using namespace nv;

int main() {
    std::string s("abcde");
    Label l("abcde", 1, 1);
    l.refresh();
    getch();
}
