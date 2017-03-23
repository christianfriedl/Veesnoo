#ifndef NV_POPUP_MENU_H
#define NV_POPUP_MENU_H

#include "Window.h"
#include "MenuItem.h"

class VerticalMenu;
namespace nv {
    class PopupMenu : public Window {
        public:
            PopupMenu(const int x, const int y); // TODO this is public... figure out how to make it callable ONLY from create()
            static std::shared_ptr<PopupMenu> create(const int x, const int y);
            const std::shared_ptr<MenuItem>& addItem(const std::shared_ptr<MenuItem>& mi);
            const std::shared_ptr<MenuItem>& addItem(const std::string& name);
            void setMenu(const std::shared_ptr<VerticalMenu>& menu);
            void addWidget(const std::shared_ptr<Widget>& widget);
            void layout();

        private:
            std::shared_ptr<VerticalMenu> menu_;

    };
}

#endif
