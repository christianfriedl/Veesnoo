/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Mapitor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */


#include "Logger.h"
#include "SelectBox.h"
#include "FocusableContainer.h"
#include "Logger.h"
#include "BasicEvent.h"

namespace nv {

    SelectBox::SelectBox(const int x, const int y): FocusableContainer(Rect(x, y, 5, 1)), menu_(PopupMenu::create(x, y + 1)), selectedItem_() { 
        LOGMETHOD("new SelectBox %s", toString().c_str());
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

    void SelectBox::addContent() {
        LOGMETHODONLY();
        addCh('\\', 0, 0);

        std::string text("...");

        if ( selectedItem_.use_count() > 0) {
            addString(selectedItem_.lock()->getText(), 1, 0);
            text = selectedItem_.lock()->getText();
        }

        if ( isFocused() || menu_->isFocused() )
            cursesWindow_->attrOn(A_REVERSE);

        addString(text, 1, 0);
        if ( isFocused() || menu_->isFocused() )
            cursesWindow_->attrOff(A_REVERSE);
        addCh('/', text.size() + 1, 0);
    }

    void 
    SelectBox::miPushed(const std::shared_ptr<BasicEvent>& ev) {
        auto tgt = std::static_pointer_cast<MenuItem>(ev->getTarget());
        Logger::get().log("SelectBox::miPushed(ev) has target %llx", tgt.get());
        selectedItem_ = tgt;
        menu_->close();
    }

    /**
     * unused, TODO needs onAfterFocus event
     */
    void 
    SelectBox::miHover(const std::shared_ptr<BasicEvent>& ev) {
        auto tgt = std::static_pointer_cast<MenuItem>(ev->getTarget());
        Logger::get().log("SelectBox::miHover(ev) has target %llx", tgt.get());
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
    void SelectBox::setMenu(const std::shared_ptr<PopupMenu>& menu) {
        menu_ = menu;
    }

    const std::shared_ptr<PopupMenu>& SelectBox::getMenu() const {
        return menu_; 
    }

    // Do not confuse this with addItem!
    void 
    SelectBox::addWidget(const std::shared_ptr<Widget>& widget) {
        Logger::get().log("SelectBox(%llx)::addWidget(%llx)", this, widget.get());
        FocusableContainer::addWidget(widget);
        layout();
    }

    bool SelectBox::receiveKey(int ch) {
        LOGMETHOD("%i, isFocused = %i", ch, isFocused());
        if ( ch == Key_Enter || ch == ' ' ) { // TODO and not open??
            menu_->open();
            return true;
        } else
            return false;
    }
}
