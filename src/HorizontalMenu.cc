#include "HorizontalMenu.h"
#include "ContainerFocusManager.h"

namespace nv {

HorizontalMenu::HorizontalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1), std::make_shared<ContainerFocusManager>(std::make_shared<FocusableContainer>(Rect(0,0,1,1)))) { 
}
std::shared_ptr<HorizontalMenu> HorizontalMenu::create(const int x, const int y) {
    auto hm = std::make_shared<HorizontalMenu>(x, y);
    hm->focusManager_->setWidget(std::shared_ptr<HorizontalMenu>(hm));
    hm->setThisToFocusManager();
}

void HorizontalMenu::pack() {
    int width = 0, i = 0;

    for ( auto widget: subWidgets_ ) {
        if ( i != 0 )
            width += 1;
        ++i;
        widget->move(width, 0);
        width += widget->getRect().getWidth();
    }
    rect.resize(width, rect.getHeight());
}

}
