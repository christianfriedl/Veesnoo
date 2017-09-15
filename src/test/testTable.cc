#include "nvwm.h"

using namespace nv;

int main() {
    auto t1(std::make_shared<Table>(Rect(0, 0, 10, 10), 3));
    for (int i = 1; i <= 5; ++i) {
        auto tc1(std::make_shared<Label>("cell", 0, 0));
        t1->addWidget(tc1);
    }
    t1->refresh();
    getch();

}
