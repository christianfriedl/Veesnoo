#ifndef NV_VERTICAL_MENU_H
#define NV_VERTICAL_MENU_H

#include "MenuItem.h"
#include "FocusableContainer.h"

namespace nv {

    class VerticalMenu: public FocusableContainer {
    public:
        VerticalMenu(const int x, const int y);
        static const std::shared_ptr<VerticalMenu> create(const int x, const int y);
        virtual ~VerticalMenu() {}
        virtual void addWidget(const std::shared_ptr<Widget>& widget);
        virtual void refresh() { Logger::get().log("VerticalMenu::refresh()"); FocusableContainer::refresh(); }

        // TODO MenuItem& addItem(const std::string& name);


    private:
        void layout(); // not virtual, because each widget will ahve to know on its own how to do this
    };

}

#endif
