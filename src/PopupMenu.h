#ifndef NV_POPUP_MENU_H
#define NV_POPUP_MENU_H

#include "Window.h"
#include "VerticalMenu.h"
#include "MenuItem.h"

namespace nv {
    class PopupMenu : public Window {
        public:
            PopupMenu(const int x, const int y);
            void addItem(MenuItem& mi);
            void pack();

        private:
            VerticalMenu menu_;
    };
}

#endif
