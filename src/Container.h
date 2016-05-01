#ifndef NV_CONTAINER_H
#define NV_CONTAINER_H

#include <vector>
#include "Widget.h"

namespace nv {

class Container: public Widget {
public:
    explicit Container(const Rect& rect): Widget(rect), subWidgets_() {}
    virtual ~Container() {}
    void addWidget(std::shared_ptr<Widget> widget);
    auto getSubWidgets() const { return subWidgets_; } // we copy the vector, because in all likelihood this will be like 10 pointers or so
    virtual void refresh();

protected:
    std::vector<std::shared_ptr<Widget> > subWidgets_;
};

}

#endif
