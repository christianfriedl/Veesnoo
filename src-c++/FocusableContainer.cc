#include "FocusableWidget.h"
#include "FocusableContainer.h"

namespace nv {

inline 
const FocusManaging& 
FocusableContainer::getFocusManager() { return *focusManager_; }

void 
FocusableContainer::addWidget(Widget& widget) {
    Container::addWidget(widget);
    FocusableWidget* f = dynamic_cast<FocusableWidget*>(&widget);
    if (f != NULL)
        focusManager_->addWidget(*f);
}

}
