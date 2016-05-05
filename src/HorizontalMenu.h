#include "FocusableContainer.h"

namespace nv {

class HorizontalMenu: public FocusableContainer {
public:
    static std::shared_ptr<HorizontalMenu> create(const int x, const int y);

    HorizontalMenu(const int x, const int y);
    virtual ~HorizontalMenu() {}
    void pack();

};
}
