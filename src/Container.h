#ifndef NV_CONTAINER_H
#define NV_CONTAINER_H

#include <memory>
#include <vector>
#include "Widget.h"
#include "Logger.h"

namespace nv {

class Container: public Widget {
public:
    explicit Container(const Rect& rect): Widget(rect), subWidgets_() {
        Logger::get().log("new Container() %s", toString().c_str());
    }
    static std::shared_ptr<Container> create(const Rect& rect);
    virtual ~Container() {
        // TODO: Will we delete the subWidgets_, or will we set teir parent to null? currently, they will be deleted along wit us
        Logger::get().log("~Container() %s", toString().c_str());
    }
    virtual void addWidget(const std::shared_ptr<Widget>& widget);
    auto getSubWidgets() const { return subWidgets_; } // we copy the vector, because in all likelihood this will be like 10 pointers or so
    int getSubWidgetsSize() const { return subWidgets_.size(); }
    virtual void refresh();
    
protected:
    std::vector<std::shared_ptr<Widget> > subWidgets_;
};

}

#endif
