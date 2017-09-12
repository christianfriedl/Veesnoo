#include "FocusableContainer.h"

namespace nv {

class HorizontalMenu: public FocusableContainer {
public:
    HorizontalMenu(const int x, const int y);
    virtual ~HorizontalMenu() {}
    virtual void addWidget(const std::shared_ptr<Widget>& widget) override;
    virtual void refresh() override { LOGMETHODONLY(); FocusableContainer::refresh(); } // just for debug
    virtual bool receiveKey(int ch) override { LOGMETHOD("%i", ch); return FocusableContainer::receiveKey(ch); } // just for debug
private:
    void layout(); // not virtual, because each widget will ahve to know on its own how to do this

};
}
