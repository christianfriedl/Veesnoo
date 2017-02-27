#include <memory>
#include <iostream>
#include "Widget.h"

int main() {
    auto w = std::make_shared<Widget>();
    w->changeInternals();
    std::cout << "w is " << w << std::endl;
    {
        std::shared_ptr<Widget> wsub1;
        auto w2 = std::make_shared<Widget>();

        std::cout << "w2 is " << w2 << std::endl;

        std::cout << "will set sub from outside" << std::endl;
        w->setSub(w2);
        std::cout << "will let widget set its own sub" << std::endl;
        wsub1 = w->getSub();
        w->addOwnSub();
        auto wPar = w2->getParent();
        wPar.lock()->changeInternals();
        std::cout << "end of inner scope" << std::endl;
    }
    std::cout << "after end of inner scope" << std::endl;
    auto wsub2 = w->getSub();

    std::cout << ", wsub2=" << wsub2 << std::endl;
    std::cout << "end of outer scope" << std::endl;
    return 0;
}
