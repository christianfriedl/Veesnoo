#include "MenuItem.h"
#include "FocusableContainer.h"

namespace nv {

class VerticalMenu: public FocusableContainer {
public:
    VerticalMenu(const int x, const int y);
    virtual ~VerticalMenu();
    void pack();

    MenuItem& addItem(const std::string& name);


private:
    std::vector<MenuItem*> addedItems_;
};
}
