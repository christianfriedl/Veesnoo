#include "Container.h"
#include "Logger.h"

namespace nv {

void 
    Container::addWidget(const std::shared_ptr<Widget>& widget) {
        /* 
         * kann es passieren, dass der parent stirbt, bevor das widget stirbt?
         * ... eigentlich, wenn der parent destruktor ENTWEDER den parent im subwidget nullt, oder
         * das subwidget deleted, dürfte das nie passieren
         */
        /*
        std::shared_ptr<Widget> weakThisWidget = shared_from_this();
        std::shared_ptr<Container> wc(dynamic_cast<Container*>(weakThisWidget.get()));
        widget->setParent(wc);
        */
        auto weakThis = std::weak_ptr<Widget>(shared_from_this());
        widget->setParent(weakThis);
        subWidgets_.emplace_back(widget);
    }

    void Container::refresh() {
        Logger::get().log("Container @%llx will refresh itself (%s)", this, toString().c_str());
        Widget::refresh();
        for ( auto widget: subWidgets_) {
            Logger::get().log("Container @%llx will refresh subWidget @ %llx", this, widget.get());
            widget.get()->refresh();
        }
    }

}
