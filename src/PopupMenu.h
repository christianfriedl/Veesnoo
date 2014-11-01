#ifndef NV_POPUP_MENU_H
#define NV_POPUP_MENU_H

#include "Window.h"
#include "VerticalMenu.h"
#include "MenuItem.h"

namespace nv {
    class PopupMenu : public Window {
        public:
            PopupMenu(const int x, const int y);
            MenuItem& addItem(MenuItem& mi);
            MenuItem& addItem(const std::string& name);
            void pack();

        private:
            VerticalMenu menu_;
    };
}

#endif
