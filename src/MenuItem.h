#ifndef NV_MENU_ITEM_H
#define NV_MENU_ITEM_H

#include "FocusableWidget.h"

namespace nv {

typedef enum { MenuItemState_normal, MenuItemState_pushed } MenuItemState;

class BasicEvent;
class MenuItem: public FocusableWidget {
public:
    MenuItem(const std::string& text, const int x, const int y);
    MenuItem(const std::string& text);
    virtual ~MenuItem() {}
    void refresh();
    bool receiveKey(int ch);
    bool push();
    sigc::signal<void, const std::shared_ptr<BasicEvent>&> onAfterPush;

private:
    std::string text_;

};

}

#endif
