#include "Logger.h"
#include "Table.h"
#include <algorithm>

namespace nv {

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
        } customLess;
        auto sorted = subWidgets_;
        std::sort(sorted.begin(), sorted.end(), customLess);

        int maxWidth = sorted[0]->getRect().getWidth();
        int paddingX = (contentRect_.getWidth() - maxWidth * numCols) / numCols;
        int numRows = subWidgets_.size() / numCols + 1;
        int paddingY = (contentRect_.getHeight() - numRows) / numRows;

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
