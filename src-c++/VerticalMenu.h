#include "FocusableContainer.h"

namespace nv {

class VerticalMenu: public FocusableContainer {
public:
    VerticalMenu(const int x, const int y);
    void pack();

};
}
