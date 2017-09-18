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


#ifndef NV_TABLE_H
#define NV_TABLE_H

#include "FocusableContainer.h"

namespace veesnoo {

    /*
     * table
     *      addrow(...)
     *      row
     *          addcell
*/

    class Table: public FocusableContainer {
        public:
            Table(Rect rect);
            Table(Rect rect, int numCols);
            virtual ~Table() {}
            // virtual void addRow(const std::shared_ptr<TableRow>& row);
            void addWidget(const std::shared_ptr<Widget>& widget) override;
            void addWidgets(const std::vector<std::shared_ptr<Widget>>& widgets);
            // virtual void addWidget(const std::shared_ptr<Widget>& widget, int col, int row);
            void refresh() override { LOGMETHODONLY(); FocusableContainer::refresh(); } // just for debug
            bool receiveKey(int ch) override { LOGMETHOD("%i", ch); return FocusableContainer::receiveKey(ch); } // just for debug
        private:
            void layout(); // not virtual, because each widget will ahve to know on its own how to do this

            std::vector<std::vector<std::shared_ptr<Widget>>> cells_;
            int numCols_;
    };
}

#endif
