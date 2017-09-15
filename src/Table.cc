#include "Logger.h"
#include "Table.h"

namespace nv {

    Table::Table(Rect rect): FocusableContainer(rect), numCols_(1) { } 
    Table::Table(Rect rect, int numCols): FocusableContainer(rect), numCols_(numCols) { } 

    /*
    void Table::addRow(const std::shared_ptr<TableRow>& row) {
        rows_.emplace_back(row);
    }
    */

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
        int x = 0, i = 0, row = 0;

        for ( auto widget: subWidgets_ ) {
            if ( x != 0 )
                x += 1;
            ++i;
            widget->move(x, row);
            x += widget->getRect().getWidth();
            if ( i % numCols_ == 0 ) {
                ++row;
                x = 0;
            }
        }
        rect_.resize(x, row);
    }

}
