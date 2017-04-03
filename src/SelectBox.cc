#include "Logger.h"
#include "SelectBox.h"
#include "FocusableContainer.h"
#include "Logger.h"
#include "BasicEvent.h"

namespace nv {

    SelectBox::SelectBox(const int x, const int y): FocusableContainer(Rect(x, y, 5, 1)), menu_(PopupMenu::create(x, y + 1)), selectedItem_() { 
        Logger::get().log("new SelectBox %s", toString().c_str());
        menu_->hide();
    }

    const std::shared_ptr<SelectBox>
    SelectBox::create(std::shared_ptr<FocusableContainer> parent, const int x, const int y) {
        auto sb = std::make_shared<SelectBox>(x, y);
        parent->addWidget(sb->menu_);
        return sb;
    }

    void 
    SelectBox::layout() {
        Logger::get().log("SelectBox::layout()");
        menu_->layout();
        Logger::get().log("SelectBox::layout() will resize to: %i %i", menu_->getRect().getWidth() + 2, 1);
        resize(menu_->getRect().getWidth() + 2, 1);
    }

    void SelectBox::refresh() { // TODO what do we output if we don't have anything...
        Logger::get().log("SelectBox(%lld)::refresh()", this);
        if ( !getIsVisibleBubbling() )
            return;
        addCh('\\', 0, 0);

        std::string text("...");

        if ( selectedItem_.use_count() > 0) {
            addString(selectedItem_->getText(), 1, 0);
            text = selectedItem_->getText();
        }

        if ( isFocused() || menu_->isFocused() )
            cursesWindow_->attrOn(A_REVERSE);

        addString(text, 1, 0);
        if ( isFocused() || menu_->isFocused() )
            cursesWindow_->attrOff(A_REVERSE);
        addCh('/', text.size() + 1, 0);
        FocusableContainer::refresh();
    }

    void 
    SelectBox::miPushed(const std::shared_ptr<BasicEvent>& ev) {
        auto tgt = std::static_pointer_cast<MenuItem>(ev->getTarget());
        Logger::get().log("SelectBox::miPushed(ev) has target %lld", tgt.get());
        selectedItem_ = tgt;
        menu_->close();
    }

    /**
     * unused, TODO needs onAfterFocus event
     */
    void 
    SelectBox::miHover(const std::shared_ptr<BasicEvent>& ev) {
        auto tgt = std::static_pointer_cast<MenuItem>(ev->getTarget());
        Logger::get().log("SelectBox::miHover(ev) has target %lld", tgt.get());
        selectedItem_ = tgt;
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
    // TODO resize myself
    void 
    SelectBox::setMenu(const std::shared_ptr<PopupMenu>& menu) {
        menu_ = menu;
    }

    // Do not confuse this with addItem!
    void 
    SelectBox::addWidget(const std::shared_ptr<Widget>& widget) {
        Logger::get().log("SelectBox(%llx)::addWidget(%llx)", this, widget.get());
        FocusableContainer::addWidget(widget);
        layout();
    }

    bool SelectBox::receiveKey(int ch) {
        if ( ch == Key_Enter || ch == ' ' ) { // TODO and not open??
            menu_->open();
            menu_->focus();
            menu_->refresh();
            return true;
        } else
            return false;
    }
}
