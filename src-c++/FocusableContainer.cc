#include "FocusableContainer.h"

namespace nv {

inline 
const FocusManaging& 
FocusableContainer::getFocusManager() { return *focusManager_; }
void FocusableContainer::addWidget(Widget& widget) {
    Container::addWidget(widget);
    // focusManager_->addWidget(widget);
}

}
