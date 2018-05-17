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


#include<algorithm>
#include"Logger.h"
#include "ContainerFocusManager.h"
#include "FocusableContainer.h"
#include "FocusableWidget.h"

namespace veesnoo {

ContainerFocusManager::ContainerFocusManager(FocusableContainer *widget) : 
        widget_(widget), focusedWidget_(nullptr), isFocused_(false) {
            LOGMETHOD("widget = %llx", widget);
}

std::shared_ptr<Focusable> 
ContainerFocusManager::getFocusedWidget() {
    return focusedWidget_;
}


bool ContainerFocusManager::bubbleReceiveKey(int ch, std::shared_ptr<Widget> w) {
    LOGMETHOD("%i", ch);
    auto f = std::dynamic_pointer_cast<Focusable> (w);

    if ( !f ) throw Exception("w is not focusable");

    if ( f.get() == dynamic_cast<Focusable*>(widget_) ) { // the widget we are requested to bubble to is our own widget
        return false;
    } else if ( f->receiveKey(ch) ) {
        return true;
    } else {
        auto ff = w->getParent().lock();
        if ( !ff )
            return false;
        return bubbleReceiveKey(ch, ff);
    }
}

bool ContainerFocusManager::receiveKey(int ch) {
    LOGMETHOD("%i", ch);
    auto fw = focusedWidget_; // we already have a focusedWidget_, therefore we need to try bubbling the event
    if ( fw )  {
        LOGMETHOD("will bubbleReceiveKey(%i, %llx)", ch, fw.get());
        if ( bubbleReceiveKey(ch, std::dynamic_pointer_cast<Widget>(fw)) )
            return true;
    } else {
        LOGMETHOD("will focusFirst()", "");
        focusFirst();
        return true;
    }
        
    if (ch == ' ' || ch == '\t' || ch == KEY_STAB || ch == KEY_DOWN || ch == KEY_RIGHT || ch == 'j' || ch == 'l') {
        LOGMETHOD("will focusNext()", "");
        focusNext();
        return true;
    }
    else if (ch == KEY_BACKSPACE || ch == KEY_BTAB || ch == KEY_UP || ch == KEY_LEFT || ch == 'k' || ch == 'h') {
        LOGMETHOD("will focusPrev()", "");
        focusPrev();
        return true;
    }
    else {
        LOGMETHOD("will return false", "");
        return false;
    }
}

void ContainerFocusManager::focus() {
    LOGMETHODONLY();
    isFocused_ = true;
    focusFirst();
}

void ContainerFocusManager::blur() {
    LOGMETHODONLY();
    isFocused_ = false;
    auto fsws = getFocusableSubWidgets();
    for ( auto w: fsws )
        w->blur();
}

std::vector<std::shared_ptr<Widget>> 
ContainerFocusManager::getSubWidgets() {
    return widget_->getSubWidgets();
}


std::vector<std::shared_ptr<Focusable>> ContainerFocusManager::getFocusableSubWidgets() {
    auto subWidgets = getSubWidgets();
    auto focusableSubWidgets = std::vector<std::shared_ptr<Focusable>>();

    for ( auto widget: subWidgets ) {
        if ( widget->getIsVisibleBubbling() ) {
            auto f = std::dynamic_pointer_cast<Focusable>(widget);
            if ( f.get() != nullptr )
                focusableSubWidgets.emplace_back(f);
        }
    }

    return focusableSubWidgets;
}

/** order the widgets:
 * - by index (not yet implemented)
 * - by y
 * - by x
 */
std::vector<std::shared_ptr<Focusable>> ContainerFocusManager::getFocusableSubWidgetsOrdered() {
        
    struct {
        bool operator()(std::shared_ptr<Focusable> w1, std::shared_ptr<Focusable> w2) const {   
            auto ww1 = std::dynamic_pointer_cast<Widget>(w1);
            auto ww2 = std::dynamic_pointer_cast<Widget>(w2);
            if ( ww1.get() == nullptr || ww2.get() == nullptr )
                return false;
            if ( ww1->getRect().getY() < ww2->getRect().getY() )
                return true;
            else if ( ww1->getRect().getY() > ww2->getRect().getY() )
                return false;
            else return ww1->getRect().getX() < ww2->getRect().getX();
        }   
    } orderByYX;
    auto subWidgets = getFocusableSubWidgets();
    std::sort(subWidgets.begin(), subWidgets.end(), orderByYX);
    return subWidgets;
}

void ContainerFocusManager::focusFirst() {
    LOGMETHODONLY();
    auto focusableSubWidgets = getFocusableSubWidgets();

    if ( focusableSubWidgets.size() != 0 ) {
        LOGMETHOD("will focus %llx", focusableSubWidgets.front().get());
        focusThis(focusableSubWidgets.front());
    }
}

void ContainerFocusManager::focusNext() {
    LOGMETHODONLY();
    auto focusableSubWidgets = getFocusableSubWidgetsOrdered();

    if (focusableSubWidgets.size() != 0) {
        std::shared_ptr<Focusable> res;
        unsigned long i=0;

        for (auto widget : focusableSubWidgets) {
            if (widget.get() == focusedWidget_.get()) {
                if (i == focusableSubWidgets.size() - 1) {
                    if ( getIsFocusStealing() || widget_->getParent().use_count() == 0 )
                        res = focusableSubWidgets[0];
                    else
                        bubbleFocusNext();
                } else
                    res = focusableSubWidgets[i+1];
                break;
            } 
            ++i;
        }
        if (res) {
            LOGMETHOD("coming from %llx, i have next focusable=%llx", focusedWidget_.get(), res.get());
            focusThis(res);
        } else {
            LOGMETHOD("coming from %llx, i have no next focusable", focusedWidget_.get());
        }
    }
}

void ContainerFocusManager::focusPrev() {
    auto focusableSubWidgets = getFocusableSubWidgetsOrdered();

    if (focusableSubWidgets.size() != 0) {
        std::shared_ptr<Focusable> res;
        int i = focusableSubWidgets.size() - 1;
        for (std::vector<std::shared_ptr<Focusable> >::reverse_iterator iter = focusableSubWidgets.rbegin(); 
                iter != focusableSubWidgets.rend(); ++iter) {
            if ((*iter) == focusedWidget_) {
                if (i == 0) {
                    if ( getIsFocusStealing() || widget_->getParent().use_count() == 0 )
                        res = focusableSubWidgets[focusableSubWidgets.size() - 1];
                    else
                        bubbleFocusPrev();
                } else
                    res = focusableSubWidgets[i-1];
                break;
            } 
            --i;
        }
        if ( res ) {
            LOGMETHOD("will focus %llx", res.get());
            focusThis(res);
        }
    }
}

void ContainerFocusManager::bubbleFocusNext() {
    std::shared_ptr<Widget> p = widget_->getParent().lock();
    if ( p ) {
        auto fcp = std::dynamic_pointer_cast<FocusableContainer>(p); // widget's parent as focusable container
        fcp->focusNext();
    } else
        throw Exception("could not cast parent to FocusableContainer");
}

void ContainerFocusManager::bubbleFocusPrev() {
    std::shared_ptr<Widget> p = widget_->getParent().lock();
    if ( p ) {
        auto fcp = std::dynamic_pointer_cast<FocusableContainer>(p); // widget's parent as focusable container
        fcp->focusPrev();
    } else
        throw Exception("could not cast parent to FocusableContainer");
}

bool ContainerFocusManager::getIsFocusStealing() {
    return widget_->getIsFocusStealing();
}

/**
 * we are requested to focus this specific widget
 */
void ContainerFocusManager::focusThis(std::shared_ptr<Focusable>& widget) {
    LOGMETHOD("will focus %llx", widget.get());
    auto focusableSubWidgets = getFocusableSubWidgets();

    focusedWidget_ = widget;
    if ( widget->isFocused() ) {
        return;
    }
    for ( auto widget: focusableSubWidgets ) {
        if ( focusedWidget_.get() == widget.get() )
            widget->focus();
        else
            widget->blur();
    }
}

bool ContainerFocusManager::isFocused() const {
    LOGMETHOD("%i", isFocused_);
    return isFocused_;
}

/**
 * we are being requested to focus the widget -- recursively
 */
void ContainerFocusManager::requestFocus(std::shared_ptr<Focusable> widget) {
    LOGMETHOD("will request focus for widget %llx", widget.get());
    if ( widget_->getParent().use_count() > 0 ) {
        std::shared_ptr<Widget> p = widget_->getParent().lock();
        if ( p ) {
            auto fcp = std::dynamic_pointer_cast<FocusableContainer>(p); // widget's parent as focusable container
            if ( !fcp )
                throw Exception("could not cast parent to FocusableContainer");
            fcp->requestFocus(widget); // ask widget_'s parent to request focus on widget
            return;
        } else
            throw Exception("could not obtain parent lock");
    } 
    focusedWidget_ = widget;
}
}
