#include <algorithm>
#include "Container.h"
#include "Logger.h"

namespace nv {
    std::shared_ptr<Container> 
    Container::create(const Rect& rect) {
        return std::make_shared<Container>(rect);
    }

    void Container::addWidget(const std::shared_ptr<Widget>& widget) {
        Logger::get().log("Container(%llx)::addWidget(%llx)", this, widget.get());
        auto weakThis = std::weak_ptr<Widget>(shared_from_this());
        widget->setParent(weakThis);
        subWidgets_.emplace_back(widget);
        Logger::get().log("Container(%llx)::addWidget after adding, has subWidgets length %i", this, subWidgets_.size());
    }

    void Container::removeWidget(const std::shared_ptr<Widget>& widget) {
        Logger::get().log("Container(%llx)::removeWidget before removing, has subWidgets length %i", this, subWidgets_.size());
        subWidgets_.erase(std::remove(subWidgets_.begin(), subWidgets_.end(), widget));
        Logger::get().log("Container(%llx)::removeWidget after removing, has subWidgets length %i", this, subWidgets_.size());
    }


    void Container::refresh() {
        Logger::get().log("Container(%llx)::refresh()  will refresh itself (%s)", this, toString().c_str());
        Logger::get().log("Container(%llx)::refresh() before w::r() has subWidgets length %i", this, subWidgets_.size());
        Widget::refresh();
        Logger::get().log("Container(%llx)::refresh() has subWidgets length %i", this, subWidgets_.size());
        for ( auto widget: subWidgets_ ) {
            Logger::get().log("Container @%llx will refresh subWidget @ %llx", this, widget.get());
            widget.get()->refresh();
        }
    }

}
