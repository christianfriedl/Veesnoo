#ifndef NV_POPUP_MENU_H
#define NV_POPUP_MENU_H

#include "MenuItem.h"
#include "PopupWindow.h"

class VerticalMenu;
namespace nv {
    class PopupMenu : public PopupWindow {
        public:
            PopupMenu(const int x, const int y); // TODO this is public... figure out how to make it callable ONLY from create()
            static std::shared_ptr<PopupMenu> create(const int x, const int y);
            const std::shared_ptr<MenuItem>& addItem(const std::shared_ptr<MenuItem>& mi);
            const std::shared_ptr<MenuItem>& addItem(const std::string& name);
            void setMenu(const std::shared_ptr<VerticalMenu>& menu);
            void addWidget(const std::shared_ptr<Widget>& widget) override;
            void layout();
            virtual void refresh() override;

        private:
            std::shared_ptr<VerticalMenu> menu_;

    };
}

#endif
