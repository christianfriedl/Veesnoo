#include "PopupMenu.h"
#include"Logger.h"

namespace nv {

    PopupMenu::PopupMenu(const int x, const int y) : Window(Rect(x, y, 1, 1), ""), menu_(1, 1) {
		Logger::get().log("new PopupMenu @ %lld", this);
        addWidget(menu_);
    }

    MenuItem& PopupMenu::addItem(MenuItem& mi) {
        menu_.addWidget(mi);
        return mi;
    }

    MenuItem& PopupMenu::addItem(const std::string& name) {
        return  menu_.addItem(name);
    }

    void 
    PopupMenu::pack() {
        menu_.pack();
        resize(menu_.getRect().getWidth() + 2, menu_.getRect().getHeight() + 2);
        calculateRects();
    }
}
