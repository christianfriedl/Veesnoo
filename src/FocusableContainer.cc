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


#include "FocusableWidget.h"
#include "FocusableContainer.h"

namespace nv {
    FocusableContainer::FocusableContainer(const Rect& rect): 
        Focusable(), Container(rect), focusManager_(new ContainerFocusManager(this)), isFocusStealing_(false) { } 

    const std::shared_ptr<FocusableContainer> FocusableContainer::create(const Rect& rect) {
        return std::make_shared<FocusableContainer>(rect);
    }

    FocusableContainer::~FocusableContainer() { 
        delete focusManager_; 
    }

    void FocusableContainer::setIsFocusStealing(bool isFocusStealing) {
        isFocusStealing_ = isFocusStealing;
    }

    bool FocusableContainer::getIsFocusStealing() {
        return isFocusStealing_;
    }

    bool FocusableContainer::receiveKey(int ch) { 
        LOGMETHOD("%i, will delegate to focusManager_ %llx", ch, focusManager_);
        return focusManager_->receiveKey(ch); 
    }

    void FocusableContainer::requestFocus(std::shared_ptr<Focusable>& widget) {
        LOGMETHOD("%llx, will delegate to focusManager_ %llx", widget.get(), focusManager_);
        focusManager_->requestFocus(widget);
    }

    void FocusableContainer::refresh() {
        LOGMETHODONLY();
        if ( !getIsVisibleBubbling() )
            return;
        Container::refresh();
        auto focusedFocusable = focusManager_->getFocusedWidget();
        if ( !focusedFocusable )
            return;
        auto focusedWidget = std::dynamic_pointer_cast<FocusableWidget>(focusedFocusable);
        if ( !focusedWidget )
            return;
        Logger::get().log("FocusableContainer(%llx)::refresh() will refresh focusedWidget %llx for last refresh", this, focusedWidget.get());
        if ( focusedWidget->getIsVisible() )
            focusedWidget->refresh();
    }

    const std::shared_ptr<FocusableContainer> FocusableContainer::findRootFocusable() {
        if ( parent_.use_count() == 0 ) {
            auto justForLogging = std::dynamic_pointer_cast<FocusableContainer>(shared_from_this());
            LOGMETHOD("returning %llx", justForLogging.get());
            return justForLogging;
        }
        auto p = parent_.lock();
        if ( !p ) throw Exception("cannot lock parent_");
        auto pp = std::dynamic_pointer_cast<FocusableContainer>(p);
        if ( !pp ) throw Exception("cannot transform parent_");
        return pp->findRootFocusable();
    }
    
    // delegates to the focusManager_
    bool FocusableContainer::isFocused() const { return focusManager_->isFocused(); }
    void FocusableContainer::focus() { 
        focusManager_->requestFocus(std::dynamic_pointer_cast<Focusable>(shared_from_this())); 
        focusManager_->focus(); 
    }
    void FocusableContainer::blur() { focusManager_->blur(); }

    void FocusableContainer::focusFirst() { focusManager_->focusFirst(); }
    void FocusableContainer::focusNext() { focusManager_->focusNext(); }
    void FocusableContainer::focusPrev() { focusManager_->focusPrev(); }
    void FocusableContainer::focusThis(std::shared_ptr<Focusable>& widget) { focusManager_->focusThis(widget); }
    std::shared_ptr<Focusable> FocusableContainer::getFocusedWidget() { return focusManager_->getFocusedWidget(); }

}
