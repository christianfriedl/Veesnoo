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


#include "ScrollPane.h"

namespace nv {

    ScrollPane::ScrollPane(Rect rect): FocusableContainer(rect), viewPort_(Point(0, 0)) { }

    void ScrollPane::addString(const std::string& text) {
        addString(text, 0, 0);
    }

    void ScrollPane::addString(const std::string& text, const int x, const int y) {
        // viewport: -10, 0
        // text from char 10
        //
        // viewport: 10, 0
        // text starts at 10
        if ( viewPort_.getY() + y >= 0 && viewPort_.getY() + y <= contentRect_.getY2() ) {
            if ( viewPort_.getX() < 0 ) {
                if ( (int)x - (int)viewPort_.getX() < (int)text.size() ) {
                    std::string xtext;
                    xtext = text.substr(-viewPort_.getX() - x);
                    FocusableContainer::addString(xtext, 0, y + viewPort_.getY());
                }
            } else if ( viewPort_.getX() < contentRect_.getX2() ) {
                FocusableContainer::addString(text, x + viewPort_.getX(), y + viewPort_.getY());
            }
        }
    }
    void ScrollPane::addStringUnscrolled(const std::string& text) {
        FocusableContainer::addString(text);
    }
    void ScrollPane::addStringUnscrolled(const std::string& text, const int x, const int y) {
        FocusableContainer::addString(text, x, y);
    }

    void ScrollPane::addCh(const int ch) {
        addCh(ch, 0, 0);
    }
    void ScrollPane::addCh(const int ch, const int x, const int y) {
        int viewPortX = -viewPort_.getX();
        int viewPortY = -viewPort_.getY();
        cursesWindow_->addCh(ch, contentRect_.getX() + x + viewPortX, contentRect_.getY() + y + viewPortY);
    }
    void ScrollPane::addChUnscrolled(const int ch) {
        FocusableContainer::addCh(ch);
    }
    void ScrollPane::addChUnscrolled(const int ch, const int x, const int y) {
        FocusableContainer::addCh(ch, x, y);
    }

    void ScrollPane::scrollTo(const int x, const int y) {
        viewPort_.setX(x);
        viewPort_.setY(y);
    }
    void ScrollPane::scrollBy(const int deltaX, const int deltaY) {
        viewPort_.setX(viewPort_.getX() + deltaX);
        viewPort_.setY(viewPort_.getY() + deltaY);
    }

}
