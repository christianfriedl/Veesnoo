#include "FocusableWidget.h"
#include "FocusableContainer.h"

namespace nv {

inline 
const FocusManaging& 
FocusableContainer::getFocusManager() const { return *focusManager_; }

void 
FocusableContainer::addWidget(std::shared_ptr<Widget> widget) {
    Container::addWidget(widget);
    FocusableWidget* f = dynamic_cast<FocusableWidget*>(widget->get());
    if (f != NULL)
        focusManager_->addWidget(std::make_shared<FocusableWidget>(*f));
}

}
