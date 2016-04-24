#ifndef NV_CONTAINER_H
#define NV_CONTAINER_H

#include <vector>
#include "Widget.h"

namespace nv {

class Container: public Widget {
public:
    Container(const Rect& rect): Widget(rect), subWidgets_() {}
    void addWidget(std::shared_ptr<Widget> widget);
    auto getSubWidgets() const { return subWidgets_; }
    virtual void refresh();

protected:
    Container(): Widget(Rect(0, 0, 1, 1)), subWidgets_() {}
    std::vector<std::shared_ptr<Widget> > subWidgets_;
};

}

#endif
