#include "VerticalMenu.h"
#include "PopupMenu.h"
#include"Logger.h"

namespace nv {

    PopupMenu::PopupMenu(const int x, const int y) : PopupWindow(Rect(x, y, 1, 1)), menu_(std::make_shared<VerticalMenu>(0, 0)) {
		LOGMETHOD("new PopupMenu %s", toString().c_str());
    }

    std::shared_ptr<PopupMenu> PopupMenu::create(const int x, const int y) {
        Logger::get().log("PopupMenu::create(%i, %i)", x, y);
        auto widget(std::make_shared<PopupMenu>(x, y));
        widget->addWidget(widget->menu_);
        return widget;
    }

    // TODO remove old menu first
    void PopupMenu::setMenu(const std::shared_ptr<VerticalMenu>& menu) {
        menu_ = menu;
    }

    void PopupMenu::addWidget(const std::shared_ptr<Widget>& widget) {
        Logger::get().log("PopupMenu(%llx)::addWidget(%llx)", this, widget.get());
        Window::addWidget(widget);
        layout();
    }


    const std::shared_ptr<MenuItem>& 
    PopupMenu::addItem(const std::shared_ptr<MenuItem>& mi) {
        Logger::get().log("PopupMenu(%llx)::addItem(%llx)", this, mi.get());
        menu_->addWidget(mi);
        layout();
        return mi;
    }

    const std::shared_ptr<MenuItem>& 
    PopupMenu::addItem(const std::string& name) {
        Logger::get().log("PopupMenu(%llx)::addItem('%s')", this, name.c_str());
        auto mi = std::make_shared<MenuItem>(name);
        return addItem(mi);
    }

    void 
    PopupMenu::layout() {
        LOGMETHODONLY();
        resize(menu_->getRect().getWidth() + 2, menu_->getRect().getHeight() + 2);
    }

}
