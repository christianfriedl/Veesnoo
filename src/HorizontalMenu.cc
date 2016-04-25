#include "HorizontalMenu.h"
#include "ContainerFocusManager.h"

namespace nv {

HorizontalMenu::HorizontalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1), std::make_unique<ContainerFocusManager>(std::shared_ptr<FocusableContainer>(this))) {
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
