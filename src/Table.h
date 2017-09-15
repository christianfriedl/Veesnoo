#ifndef NV_TABLE_H
#define NV_TABLE_H

#include "FocusableContainer.h"
#include "TableRow.h"

namespace nv {

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
            virtual void addWidget(const std::shared_ptr<Widget>& widget) override;
            // virtual void addWidget(const std::shared_ptr<Widget>& widget, int col, int row);
            virtual void refresh() override { LOGMETHODONLY(); FocusableContainer::refresh(); } // just for debug
            virtual bool receiveKey(int ch) override { LOGMETHOD("%i", ch); return FocusableContainer::receiveKey(ch); } // just for debug
        private:
            void layout(); // not virtual, because each widget will ahve to know on its own how to do this

            std::vector<std::vector<std::shared_ptr<Widget>>> cells_;
            int numCols_;
    };
}

#endif
