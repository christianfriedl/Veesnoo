#include "Logger.h"
#include "VerticalMenu.h"
#include "ContainerFocusManager.h"

namespace nv {

    VerticalMenu::VerticalMenu(const int x, const int y): FocusableContainer(Rect(x, y, 1, 1)) { 
        LOGMETHODONLY();
    }

    const std::shared_ptr<VerticalMenu>
    VerticalMenu::create(const int x, const int y) {
        return std::make_shared<VerticalMenu>(x, y);
    }

    void VerticalMenu::addWidget(const std::shared_ptr<Widget>& widget) {
        Logger::get().log("VerticalMenu(%llx)::addWidget(%llx)", this, widget.get());
        FocusableContainer::addWidget(widget);
        layout();
    }

    void VerticalMenu::layout() {
        int width = 0, height = 0;
        Logger::get().log("VerticalMenu::layout()");
        Logger::get().log("VerticalMenu::layout() start has subWidgets length %i", subWidgets_.size());

        for ( auto widget: subWidgets_ ) {
            widget->move(0, height);
            width = std::max(width, widget->getRect().getWidth());
            ++height;
        }
        Logger::get().log("VerticalMenu(%llx)::layout() determines rect: %i, %i", this, width, height);
        resize(width, height);
        Logger::get().log("VerticalMenu::layout() end has subWidgets length %i", subWidgets_.size());
    }

}
