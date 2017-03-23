#ifndef NV_VERTICAL_MENU_H
#define NV_VERTICAL_MENU_H

#include "MenuItem.h"
#include "PopupMenu.h"

namespace nv {

    class SelectBox: public FocusableContainer {
    public:
        SelectBox(const int x, const int y);
        static const std::shared_ptr<SelectBox> create(const int x, const int y);
        virtual ~SelectBox() {}
        virtual void addWidget(const std::shared_ptr<Widget>& widget) override;
        const std::shared_ptr<MenuItem>& addItem(const std::shared_ptr<MenuItem>& mi);
        const std::shared_ptr<MenuItem>& addItem(const std::string& name, const std::string& value);
        void setMenu(const std::shared_ptr<PopupMenu>& menu);
        void miPushed(const std::shared_ptr<BasicEvent>& ev);

    private:
        void layout(); // not virtual, because each widget will ahve to know on its own how to do this
        std::shared_ptr<PopupMenu> menu_;
    };

}

#endif
