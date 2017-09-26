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
#include <iostream>
#include <sstream>

namespace veesnoo {
FocusableWidget::FocusableWidget(const Rect& rect): Focusable(), Widget(rect), isFocused_(false),
    contentFocusedColorAttribute_(std::shared_ptr<ColorAttribute>(nullptr)),
    borderFocusedColorAttribute_(std::shared_ptr<ColorAttribute>(nullptr))
    {
    }

FocusableWidget::FocusableWidget(): Focusable(), Widget(), isFocused_(false),
    contentFocusedColorAttribute_(std::shared_ptr<ColorAttribute>(nullptr)),
    borderFocusedColorAttribute_(std::shared_ptr<ColorAttribute>(nullptr))
    {
    }

#pragma clang diagnostic ignored "-Wunused-parameter"
bool FocusableWidget::receiveKey(int ch) {
    LOGMETHOD("%i", ch);
    return false;
}

void FocusableWidget::focus() {
    LOGMETHOD("%s", toString().c_str());
    isFocused_ = true;
    // we do not have a separate FocusManager, therefore we need to ask our own parent for the focus
    auto p = parent_.lock();
    if ( p ) {
        auto fcp = std::dynamic_pointer_cast<FocusableContainer>(p);
        if ( !fcp )
            throw Exception("cannot cast parent to FocusableContainer");
        std::shared_ptr<Focusable> fthis = std::dynamic_pointer_cast<Focusable>(shared_from_this());
        if ( !fthis )
            throw Exception("cannot cast this to Focusable");
        LOGMETHOD("will request focus for %llx from %llx", fthis.get(), fcp.get());
        fcp->requestFocus(fthis); // TODO probably should return bool?
    }
}

void FocusableWidget::blur() {
    LOGMETHOD("%s", toString().c_str());
    isFocused_ = false;
}

bool FocusableWidget::isFocused() const {
    return isFocused_;
}

std::shared_ptr<ColorAttribute> FocusableWidget::getContentColorAttribute(bool focused) {
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
            contentFocusedColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_RED, COLOR_BLUE);
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
            contentColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_RED, COLOR_BLUE);
        }
        return contentColorAttribute_;
    }
}

std::shared_ptr<ColorAttribute> FocusableWidget::getBorderColorAttribute(bool focused) {
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
            borderFocusedColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_RED, COLOR_BLUE);
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
            borderColorAttribute_ = std::make_shared<ColorAttribute>(COLOR_RED, COLOR_BLUE);
        }
        return borderColorAttribute_;
    }
}

std::shared_ptr<ColorAttribute> FocusableWidget::getContentColorAttribute() {
    return getContentColorAttribute(isFocused());
}

std::shared_ptr<ColorAttribute> FocusableWidget::getBorderColorAttribute() {
    return getBorderColorAttribute(isFocused());
}

void FocusableWidget::setContentFocusedColorAttribute(std::shared_ptr<ColorAttribute> colorAttribute) {
    contentFocusedColorAttribute_ = colorAttribute;
}
void FocusableWidget::setBorderFocusedColorAttribute(std::shared_ptr<ColorAttribute> colorAttribute) {
    borderFocusedColorAttribute_ = colorAttribute;
}

const std::string FocusableWidget::toString() const {
    std::ostringstream ostr;
    ostr << "<FocusableWidget " << Widget::toString();
    ostr << "isFocused=" << isFocused_ << ">";
    return ostr.str();
}

}
