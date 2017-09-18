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
#include "Table.h"
#include <algorithm>

namespace veesnoo {

    Table::Table(Rect rect): FocusableContainer(rect), numCols_(1) { } 
    Table::Table(Rect rect, int numCols): FocusableContainer(rect), numCols_(numCols) { } 

    void Table::addWidgets(const std::vector<std::shared_ptr<Widget>>& widgets) {
        for ( auto widget: widgets )
            addWidget(widget);
    }

    void Table::addWidget(const std::shared_ptr<Widget>& widget) {
        if ( cells_.size() == 0 )
            cells_.emplace_back(std::vector<std::shared_ptr<Widget>>());
        if ( cells_[cells_.size()].size() == (size_t)numCols_ )
            cells_.emplace_back(std::vector<std::shared_ptr<Widget>>());
        cells_[cells_.size() - 1].emplace_back(widget);
        FocusableContainer::addWidget(widget);
        layout();
    }

    void Table::layout() {
        LOGMETHODONLY();
        if ( subWidgets_.size() == 0 ) return;
        int x = 0, i = 0, y = 0;
        int numCols = subWidgets_.size() >= (size_t)numCols_ ? numCols_ : subWidgets_.size();
        struct {
            bool operator()(std::shared_ptr<Widget> w1, std::shared_ptr<Widget> w2) const
            {   
                return w1->getRect().getWidth() > w2->getRect().getWidth();
            }   
        } customLessWidth;
        struct {
            bool operator()(std::shared_ptr<Widget> w1, std::shared_ptr<Widget> w2) const
            {   
                return w1->getRect().getHeight() > w2->getRect().getHeight();
            }   
        } customLessHeight;
        auto sortedWidth = subWidgets_;
        std::sort(sortedWidth.begin(), sortedWidth.end(), customLessWidth);
        auto sortedHeight = subWidgets_;
        std::sort(sortedHeight.begin(), sortedHeight.end(), customLessHeight);

        int maxWidth = sortedWidth[0]->getRect().getWidth();
        int maxHeight = sortedHeight[0]->getRect().getHeight();

        int paddingX = (contentRect_.getWidth() - maxWidth * numCols) / numCols;
        int numRows = subWidgets_.size() / numCols + 1;
        int paddingY = (contentRect_.getHeight() - maxHeight * numRows) / numRows;

        for ( auto widget: subWidgets_ ) {
            if ( x != 0 )
                x += paddingX;
            ++i;
            widget->move(x, y);
            x += widget->getRect().getWidth();
            if ( i % numCols_ == 0 ) {
                y += 1 + paddingY;
                x = 0;
            }
        }
        rect_.resize(x, y);
    }

}
