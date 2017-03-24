#include "Logger.h"
#include "SelectBox.h"
#include "FocusableContainer.h"

namespace nv {

    SelectBox::SelectBox(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)), menu_(PopupMenu::create(x, y + 1)) { 
        Logger::get().log("new SelectBox %s", toString().c_str());
    }

    const std::shared_ptr<SelectBox>
    SelectBox::create(std::shared_ptr<FocusableContainer> parent, const int x, const int y) {
        auto sb = std::make_shared<SelectBox>(x, y);
        parent->addWidget(sb->menu_);
        return sb;
    }

    void 
    SelectBox::layout() {
        menu_->layout();
    }

    void 
    SelectBox::miPushed(const std::shared_ptr<BasicEvent>& ev) {
    }


    const std::shared_ptr<MenuItem>& 
    SelectBox::addItem(const std::shared_ptr<MenuItem>& mi) {
        Logger::get().log("SelectBox(%llx)::addItem(%llx)", this, mi.get());
        mi->onAfterPush.connect(sigc::mem_fun(this, &SelectBox::miPushed) );
        menu_->addItem(mi);
        layout();
        return mi;
    }

    const std::shared_ptr<MenuItem>& 
    SelectBox::addOption(const std::string& name, const std::string& value) {
        Logger::get().log("SelectBox(%llx)::addOption('%s', '%s')", this, name.c_str(), value.c_str());
        auto mi = std::make_shared<MenuItem>(name);
        return addItem(mi);
    }

    // TODO remove old menu first
    void 
    SelectBox::setMenu(const std::shared_ptr<PopupMenu>& menu) {
        menu_ = menu;
    }

    void 
    SelectBox::addWidget(const std::shared_ptr<Widget>& widget) {
        Logger::get().log("SelectBox(%llx)::addWidget(%llx)", this, widget.get());
        FocusableContainer::addWidget(widget);
        layout();
    }
}
