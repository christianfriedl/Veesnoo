#ifndef NV_POPUP_MENU_H
#define NV_POPUP_MENU_H

#include "Window.h"
#include "VerticalMenu.h"
#include "MenuItem.h"

namespace nv {
    class PopupMenu : public Window {
        public:
            PopupMenu(const int x, const int y);
            const std::shared_ptr<MenuItem>& addItem(const std::shared_ptr<MenuItem>& mi);
            const std::shared_ptr<MenuItem>& addItem(const std::string& name);
            void setMenu(const std::shared_ptr<VerticalMenu>& menu);
            void addWidget(const std::shared_ptr<Widget>& widget);

        private:
            std::shared_ptr<VerticalMenu> menu_;

            void layout();
    };
}

#endif
