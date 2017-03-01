#include "MenuItem.h"
#include "VerticalMenu.h"
#include "MainLoop.h"

using namespace nv;

int main() {
    auto m1 (std::make_shared<MenuItem>("menuitem1"));
    auto m2 (std::make_shared<MenuItem>("menuitem2"));
    auto m3 (std::make_shared<MenuItem>("menuitem3"));
    auto hm = std::make_shared<VerticalMenu>(6, 2);
    hm->addWidget(m1);
    hm->addWidget(m2);
    hm->addWidget(m3);

    MainLoop ml(hm);
    ml.run();
}
