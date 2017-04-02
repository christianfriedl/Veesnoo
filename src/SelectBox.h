#ifndef NV_VERTICAL_MENU_H
#define NV_VERTICAL_MENU_H

#include "Label.h"
#include "MenuItem.h"
#include "PopupMenu.h"

namespace nv {

    class SelectBox: public FocusableContainer {
    public:
        SelectBox(const int x, const int y);
        static const std::shared_ptr<SelectBox> create(std::shared_ptr<FocusableContainer> parent, const int x, const int y);
        virtual ~SelectBox() {}
        virtual void addWidget(const std::shared_ptr<Widget>& widget);
        const std::shared_ptr<MenuItem>& addItem(const std::shared_ptr<MenuItem>& mi);
        const std::shared_ptr<MenuItem>& addOption(const std::string& name, const std::string& value);
        void setMenu(const std::shared_ptr<PopupMenu>& menu);
        void miPushed(const std::shared_ptr<BasicEvent>& ev);
        void miHover(const std::shared_ptr<BasicEvent>& ev);
        virtual void refresh();
        virtual void focus();
        virtual void deFocus();

    private:
        void layout(); // not virtual, because each widget will ahve to know on its own how to do this
        std::shared_ptr<PopupMenu> menu_;
        std::shared_ptr<MenuItem> selectedItem_;
    };

}

#endif
