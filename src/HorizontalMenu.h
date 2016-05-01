#include "FocusableContainer.h"

namespace nv {

class HorizontalMenu: public FocusableContainer {
public:
    HorizontalMenu(const int x, const int y);
    virtual ~HorizontalMenu() {}
    void pack();

};
}
