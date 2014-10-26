#include "PopupMenu.h"

namespace nv {

    PopupMenu::PopupMenu(const int x, const int y) : Window(Rect(x, y, 1, 1), ""), menu_(0, 0) {}

    void PopupMenu::addItem(MenuItem& mi) {
        menu_.addWidget(mi);
    }

    void PopupMenu::pack() {
        menu_.pack();
        rect->resize(menu_.getRect().getWidth(), menu_.getRect().getHeight());
    }
    
}
