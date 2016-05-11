#include "FocusableContainer.h"

namespace nv {

class HorizontalMenu: public FocusableContainer {
public:
    static std::shared_ptr<HorizontalMenu> create(const int x, const int y);

    HorizontalMenu(const int x, const int y);
    virtual ~HorizontalMenu() {}
    virtual void addWidget(const std::shared_ptr<Widget>& widget) override;
private:
    void layout(); // not virtual, because each widget will ahve to know on its own how to do this

};
}
