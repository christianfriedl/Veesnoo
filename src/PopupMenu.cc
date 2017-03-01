#include "PopupMenu.h"
#include"Logger.h"

namespace nv {

    PopupMenu::PopupMenu(const int x, const int y) : Window(Rect(x, y, 1, 1)), menu_(std::make_shared<VerticalMenu>(0, 0)) {
		Logger::get().log("new PopupMenu %s", toString().c_str());
    }

    // TODO remove old menu first
    void PopupMenu::setMenu(const std::shared_ptr<VerticalMenu>& menu) {
        menu_ = menu;
        addWidget(menu_);
    }

    void 
    PopupMenu::addWidget(const std::shared_ptr<Widget>& widget) {
        Window::addWidget(widget);
        layout();
    }


    const std::shared_ptr<MenuItem>& 
    PopupMenu::addItem(const std::shared_ptr<MenuItem>& mi) {
        menu_->addWidget(mi);
        layout();
        return mi;
    }

    const std::shared_ptr<MenuItem>& 
    PopupMenu::addItem(const std::string& name) {
        auto mi = std::make_shared<MenuItem>(name);
        return addItem(mi);
    }

    void 
    PopupMenu::layout() {
        if ( subWidgets_.size() == 0 ) // work around shared_ptr-in-cons issue
            addWidget(menu_);
        resize(menu_->getRect().getWidth() + 2, menu_->getRect().getHeight() + 2);
    }
}
