#include "HorizontalMenu.h"
#include "ContainerFocusManager.h"

namespace nv {

HorizontalMenu::HorizontalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)) {
    focusManager_ = new ContainerFocusManager(*this); 
}

void HorizontalMenu::pack() {
    int width = 0;
    std::vector<Widget *>::iterator iter;

    for ( iter = subWidgets_.begin(); iter != subWidgets_.end(); ++iter ) {
        if ( iter != subWidgets_.begin() )
            width += 1;
        (*iter)->move(width, 0);
        width += (*iter)->getRect().getWidth();
    }
    rect->resize(width, rect->getHeight());
}

}
