#include "VerticalMenu.h"
#include "ContainerFocusManager.h"

namespace nv {

VerticalMenu::VerticalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)) {
    focusManager_ = new ContainerFocusManager(*this); 
}

void VerticalMenu::pack() {
    int i = 0;
    std::vector<Widget *>::iterator iter;

    for ( iter = subWidgets_.begin(); iter != subWidgets_.end(); ++iter, ++i ) {
        (*iter)->move(0, i);
    }
    rect->resize(rect->getWidth(), i);
}

}
