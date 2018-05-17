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

namespace veesnoo {
    FocusableContainer::FocusableContainer(const Rect& rect): 
        Focusable(), Container(rect), focusManager_(new ContainerFocusManager(this)), isFocusStealing_(false),
        contentFocusedColorAttribute_(std::shared_ptr<ColorAttribute>(nullptr)),
        borderFocusedColorAttribute_(std::shared_ptr<ColorAttribute>(nullptr))
    { 
    } 

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

    std::shared_ptr<ColorAttribute> FocusableContainer::getContentColorAttribute(bool focused) {
        if ( focused ) {
            if ( contentFocusedColorAttribute_.use_count() == 0 && parent_.use_count() > 0 ) {
                auto p = parent_.lock();
                if ( !p )
                    throw Exception("unable to lock parent");
                auto fwp = std::dynamic_pointer_cast<FocusableContainer>(p);
                if ( !fwp )
                    throw Exception("unable to cast parent");
                contentFocusedColorAttribute_ = fwp->getContentColorAttribute(focused);
            }
            if ( contentFocusedColorAttribute_.use_count() == 0 ) {
                contentFocusedColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_WHITE, COLOR_BLACK, true);
            }
            return contentFocusedColorAttribute_;
        } else {
            if ( contentColorAttribute_.use_count() == 0 && parent_.use_count() > 0 ) {
                auto p = parent_.lock();
                if ( !p )
                    throw Exception("unable to lock parent");
                auto fwp = std::dynamic_pointer_cast<FocusableContainer>(p);
                if ( !fwp )
                    throw Exception("unable to cast parent");
                contentColorAttribute_ = fwp->getContentColorAttribute(focused);
            }
            if ( contentColorAttribute_.use_count() == 0 ) {
                contentColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_WHITE, COLOR_BLACK);
            }
            return contentColorAttribute_;
        }
    }

    std::shared_ptr<ColorAttribute> FocusableContainer::getBorderColorAttribute(bool focused) {
        if ( focused ) {
            if ( borderFocusedColorAttribute_.use_count() == 0 && parent_.use_count() > 0 ) {
                auto p = parent_.lock();
                if ( !p )
                    throw Exception("unable to lock parent");
                auto fwp = std::dynamic_pointer_cast<FocusableContainer>(p);
                if ( !fwp )
                    throw Exception("unable to cast parent");
                borderFocusedColorAttribute_ = fwp->getBorderColorAttribute(focused);
            }
            if ( borderFocusedColorAttribute_.use_count() == 0 ) {
                borderFocusedColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_WHITE, COLOR_BLACK, true);
            }
            return borderFocusedColorAttribute_;
        } else {
            if ( borderColorAttribute_.use_count() == 0 && parent_.use_count() > 0 ) {
                auto p = parent_.lock();
                if ( !p )
                    throw Exception("unable to lock parent");
                auto fwp = std::dynamic_pointer_cast<FocusableContainer>(p);
                if ( !fwp )
                    throw Exception("unable to cast parent");
                borderColorAttribute_ = fwp->getBorderColorAttribute(focused);
            }
            if ( borderColorAttribute_.use_count() == 0 ) {
                borderColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_WHITE, COLOR_BLACK);
            }
            return borderColorAttribute_;
        }
    }

    std::shared_ptr<ColorAttribute> FocusableContainer::getContentColorAttribute() {
        return getContentColorAttribute(isFocused());
    }

    std::shared_ptr<ColorAttribute> FocusableContainer::getBorderColorAttribute() {
        return getBorderColorAttribute(isFocused());
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
        if ( focusedWidget->getIsVisible() ) {
            focusedWidget->refresh();
            CursesManager::get().doupdate();
        }
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

    void FocusableContainer::setContentFocusedColorAttribute(std::shared_ptr<ColorAttribute> colorAttribute) {
        contentFocusedColorAttribute_ = colorAttribute;
    }
    void FocusableContainer::setBorderFocusedColorAttribute(std::shared_ptr<ColorAttribute> colorAttribute) {
        borderFocusedColorAttribute_ = colorAttribute;
    }

}
